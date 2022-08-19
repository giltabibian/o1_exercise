#include "IServiceA.h"

namespace services {

Element defaultValue = {0, ""};

void IServiceA::Init(int maxCount) {
  elements.resize(maxCount, defaultValue);
  all = defaultValue;
  id = 0;
}

string IServiceA::Get(int index) { 
  if(all.id > elements.at(index-1).id) 
    return all.value;
  else 
    return elements.at(index-1).value;
}

void IServiceA::Set(int index, string val) { 
  elements.at(index -1) = {id++, val};
}

void IServiceA::SetAll(string val) {
  all = {id++, val};
}

}