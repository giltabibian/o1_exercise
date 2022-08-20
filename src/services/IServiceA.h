#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


namespace services {

  struct Element {
    uint8_t   id;
    string    value;
  };
  
class IServiceA {
private:
    uint8_t         id;
    Element         all;
    vector<Element> elements;

public:
  void Init(int maxCount);
  string Get(int index);
  void Set(int index, string val);
  void SetAll(string val);

  uint8_t getId(int index);
  uint8_t getAllId();

  IServiceA(int maxCount){
    Init(maxCount);
  }

};

}