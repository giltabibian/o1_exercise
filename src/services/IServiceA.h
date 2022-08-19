#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


namespace services {

  struct Element {
    int id;
    string value;
  };
  
class IServiceA {
private:
    int             id;
    Element         all;
    vector<Element> elements;

public:
  void Init(int maxCount);
  string Get(int index);
  void Set(int index, string val);
  void SetAll(string val);

  IServiceA(size_t maxCount){
    Init(maxCount);
  }

};

}