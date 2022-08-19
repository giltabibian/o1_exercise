#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace src::services {

  struct Element {
    size_t id;
    std::string value;
  };

  struct DataBase {
    size_t      id;
    Element     all;
    static std::unordered_map<size_t, Element> elementsArray;
  };
  
class IServiceA {
private:
  DataBase dataBase;

public:
  void Init(size_t maxCount) {
    dataBase.elementsArray.reserve(maxCount);
  }

  IServiceA(size_t maxCount){
    Init(maxCount);
  }

};

}