#include "IServiceA.h"

namespace services {

void IServiceA::Init(size_t maxCount) {
  dataBase.elements.reserve(maxCount);
}

}