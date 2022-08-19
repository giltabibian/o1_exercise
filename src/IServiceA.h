#pragma once

#include <string>
#include <vector>

namespace o1_exercise {

  struct Element {
    size_t id, 
    std::string value
  };

  struct DataBase {
    size_t      id
    Element     all
    static std::unordered_map<size_t index, Element>> elementsArray = {}
  };
  
class IServiceA {
private:
  DataBase dataBase;

public:
  void Init(size_t maxCount) {
    dataBase.elementsArray.reserve(maxCount);
  }

};

}