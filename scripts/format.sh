#!/bin/bash

set -eo pipefail

script_dir=$(realpath $(dirname $0))
cd ${script_dir}/..
relative_script_path="$(realpath --relative-to="." "$0")"
source $script_dir/common.sh

root_dir=$(realpath $script_dir/..)

# arguments
method=dry-run
is_interactive=false
difftool=diff

# global variables
tmp_file=


usage="
usage: "$(basename $0)" [OPTIONS]

OPTIONS

  -h,--help             show this mesage
  -v,--verbose          verbose mode

  -m,--method           specify what to do.
                        options: dry-run, in-place, diff
                        default: $method

  -i,--interactive      enable interactive mode.
                        let the script ask per file whether to perform the required method.

  --difftool            specify what command to execute when running diff.
                        default: $difftool

EXAMPLES

  # check what files will the scripts act upon
  $relative_script_path

  # format the whole project
  $relative_script_path -m in-place

  # format the whole project interactively
  $relative_script_path -i -m in-place

  # create diffs for the whole project interactively
  $relative_script_path -i -m diff

  # create diffs for the whole project interactively using meld
  $relative_script_path -i -m diff  --difftool meld
"

while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help) echo "$usage"; exit 0;;
        -v|--versbose) debug_enabled=true; shift;;
        -m|--method) method=$2; shift; shift;;
        -i|--interactive) is_interactive=true; shift;;
        -n|--dry-run) dry_run=true; shift;;
        --difftool) difftool=$2; shift; shift;;
        --) specfied_files=true; shift; break;;
        *) error "unknown argument: $1";;
    esac
done

function run_dry_run() {
    info "will format: $1"
}

function run_in_place() {
    file=$1
    clang-format -style=file -i $file
}

function run_diff() {
    file=$1

    # write the formatted file to the temporary file
    if [[ ! -f $tmp_file ]]; then
        tmp_file=$(mktemp);
        debug "created a temporary file for diff at: $tmp_file" || true
    fi
    clang-format -style=file $file > $tmp_file
    set +e
    $difftool $file $tmp_file
}

function join_by { local IFS="$1"; shift; echo "$*"; }

has_failed=0
dirs=("src" "apps" "tests")
extensions=("cpp" "h")

dirs_regex=$(join_by '|' ${dirs[@]})
extensions_regex=$(join_by '|' ${extensions[@]})

# Collect files
if [[ $specfied_files == true ]]
then
    for file in $@; do
        [[ "$file" =~ ^($dirs_regex).*\.($extensions_regex)$ ]] && files="$files $file"
    done
else
    files=$(find ${dirs[@]} -type f | grep -E "\.($extensions_regex)$")
fi

if [[ ! -z $files ]]; then
    for file in $files; do
        if [[ $is_interactive == true ]]; then
            file_dir=$(dirname $file)
            file_name=$(basename $file)
            echo -e -n "do you want to \e[1m\e[33m$method\e[0m \"$file_dir/\e[1m\e[31m$file_name\e[0m\"? (y/n) "
            read -n 1 -r
            echo ""
            [[ $REPLY =~ ^[Yy]$ ]] || continue 1;
        fi

        case $method in
            dry-run) run_dry_run $file;;
            in-place) run_in_place $file;;
            diff) run_diff $file
                if [ $? != 0 ]; then
                    echo "$file"
                    has_failed=1
                fi
                set -e
                ;;
            *) error "invalid method: $method";;
        esac
    done
fi

# This will enable outsider to know if the diff failed
# Only relevant when run with diff method...
exit $has_failed
