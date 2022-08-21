#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace services {

/* using timestamp: 
day in microseconds: 1000000x60x60x24 = 86400000000
uint64_6 granularity: 18446744073709551616
days in uint_64: 18446744073709551616 / 86400000000 = 213503982
years: 213503982 / 365 = 584942
*/
struct Element {
    int64_t timestamp;
    string value;
};

class IServiceA {
private:
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
    int64_t getTimestamp(int index);
    int64_t getAllTimestamp();
};

} // namespace services