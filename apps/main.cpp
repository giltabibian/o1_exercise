#include "src/services/IServiceA.h"

#include <iostream>

using std::cout;

int main() {
    services::IServiceA service(100);

    service.Set(1, "1");
    service.SetAll("2");
    service.Set(2, "3");
    service.Set(32, "4");
    cout << service.Get(1) << "\n";
    cout << service.Get(2) << "\n";
    return 0;
}