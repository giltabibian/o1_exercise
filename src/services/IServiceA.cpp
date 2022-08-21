#include "IServiceA.h"
#include <assert.h>
#include <limits>
#include <stdexcept>
namespace services {

const uint64_t maxLimit = std::numeric_limits<uint64_t>::max();

void IServiceA::Init(int maxCount) {
    elements.resize(maxCount, defaultValue);
    all = defaultValue;
    id = 0;
}

string IServiceA::Get(int index) {
    if (all.id > elements.at(index).id)
        return all.value;
    else
        return elements.at(index).value;
}

void IServiceA::Set(int index, string val) {
    assert(id < maxLimit);
    elements.at(index) = {++id, val};
}

void IServiceA::SetAll(string val) {
    assert(id < maxLimit);
    all = {++id, val};
}

void IServiceA::setId(const uint64_t id) {
    this->id = id;
}

uint64_t IServiceA::getId(const int index) {
    return elements.at(index).id;
}

uint64_t IServiceA::getAllId() {
    return all.id;
}

} // namespace services