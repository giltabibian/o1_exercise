#!/bin/bash -eu

# log

function error() {
    echo -e "\e[31m[EROR]\e[0m $1"; exit 1
}

function warn() {
    echo -e "\e[33m[WARN]\e[0m $1" 1>&2
}

function info() {
    echo -e "\e[32m[INFO]\e[0m $1"
}

function debug() {
    [[ $debug_enabled == true ]] && echo -e "\e[33m[DEBG]\e[0m $1"
}

# build

function setBuildVariables {
    # BASH_SOURCE[0] is the most reliable way to get the path of common.sh, since
    # it is sourced from other scripts and therefore $0 can't be used.
    REL_SCRIPT_DIR=`dirname ${BASH_SOURCE[0]}`

    SCRIPT_DIR=`realpath $REL_SCRIPT_DIR`
    BUILD_ROOT="$SCRIPT_DIR/../build"
    BIN_DEBUG="$SCRIPT_DIR/../build/debug/bin"
    BIN_RELEASE="$SCRIPT_DIR/../build/release/bin"
    SRC_DIR=`realpath $SCRIPT_DIR/..`

    INCLUDES=" \
        -I$SRC_DIR/src \
        -I$SRC_DIR/tests/ \
        -isystem $SRC_DIR/third_party/catch"

    WARN_FLAGS=" \
        -Wall \
        -Wextra \
        -pedantic \
        -Werror \
        -Wno-gnu-zero-variadic-macro-arguments \
        -Wno-non-template-friend \
        -Wno-unknown-warning-option \
        -Wno-unknown-attributes \
        -Wno-unused-parameter \
        -Wno-unused-command-line-argument \
        -Wno-unused-function"

    EXTRA_PEDANTIC_CLANG_WARN_FLAGS=" \
        -Weverything \
        -ferror-limit=1000 \
        -Wno-c++98-compat \
        -Wno-c++98-compat-pedantic \
        -Wno-shadow-field-in-constructor \
        -Wno-sign-conversion \
        -Wno-shadow-field \
        -Wno-newline-eof"

    ARCH_FLAGS=" \
        -march=haswell \
        -mno-popcnt \
        -mno-rdrnd"

    BUILD_FLAGS=" \
        -fPIC \
        -pthread \
        -std=c++2a"
}
