#include "IServiceA.h"
#include <chrono>

using namespace std::chrono;

namespace services {

int64_t calcCurrentTime() {
    return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}

void IServiceA::Init(int maxCount) {
    elements.resize(maxCount, {calcCurrentTime(), ""});
    all = {calcCurrentTime(), ""};
    timestamp = calcCurrentTime();
}

string IServiceA::Get(int index) {
    if (all.timestamp > elements.at(index).timestamp)
        return all.value;
    else
        return elements.at(index).value;
}

void IServiceA::Set(int index, string val) {
    elements.at(index) = {calcCurrentTime(), val};
}

void IServiceA::SetAll(string val) {
    all = {calcCurrentTime(), val};
}

int64_t IServiceA::getTimestamp(int index) {
    return elements.at(index).timestamp;
}

int64_t IServiceA::getAllTimestamp() {
    return all.timestamp;
}

} // namespace services