#include "IServiceA.h"

namespace services {

void IServiceA::Init(size_t maxCount) {
  dataBase.elementsArray.reserve(maxCount);
}

}