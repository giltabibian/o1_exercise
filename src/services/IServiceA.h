#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace services {

struct Element {
    int64_t id;
    string value;
};

class IServiceA {
private:
    int64_t id;
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
    int64_t getId(int index);
    int64_t getAllId();
};

} // namespace services