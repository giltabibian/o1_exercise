#pragma once

#include <string>
#include <vector>
#include <chrono>

using std::string;
using std::vector;
using namespace std::chrono;

namespace services {

  struct Element {
    int64_t   timestamp;
    string    value;
  };
  
class IServiceA {
private:
    int64_t         timestamp;
    Element         all;
    vector<Element> elements;

public:
  void Init(int maxCount);
  string Get(int index);
  void Set(int index, string val);
  void SetAll(string val);

  int64_t getTimestamp(int index);
  int64_t getAllTimestamp();

  IServiceA(int maxCount){
    Init(maxCount);
  }

};

}