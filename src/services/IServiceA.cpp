#include "IServiceA.h"
#include <chrono>

using namespace std::chrono;
namespace services {

const Element defaultValue = {duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(), ""};

void IServiceA::Init(int maxCount) {
    elements.resize(maxCount, defaultValue);
    all = defaultValue;
    timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

string IServiceA::Get(int index) {
    if (all.timestamp > elements.at(index).timestamp)
        return all.value;
    else
        return elements.at(index).value;
}

void IServiceA::Set(int index, string val) {
    elements.at(index) = {++timestamp, val};
}

void IServiceA::SetAll(string val) {
    all = {++timestamp, val};
}

int64_t IServiceA::getTimestamp(int index) {
    return elements.at(index).timestamp;
}

int64_t IServiceA::getAllTimestamp() {
    return all.timestamp;
}

} // namespace services