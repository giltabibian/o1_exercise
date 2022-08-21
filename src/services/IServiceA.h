#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;
namespace services {
struct Element {
    uint64_t id;
    string value;
};
class IServiceA {
private:
    uint64_t id;
    Element all;
    vector<Element> elements;

public:
    void Init(int maxCount);
    string Get(int index);
    void Set(int index, string val);
    void SetAll(string val);

    IServiceA(int maxCount) {
        Init(maxCount);
    }

    // debug functions
    void setId(uint64_t id);
    uint64_t getId(int index);
    uint64_t getAllId();
};

} // namespace services