#define CATCH_CONFIG_MAIN
#include "test_utils.h"
#include <iostream>

#include "src/services/IServiceA.h"

using std::cout;

TEST_CASE_O1( "basic", "[functionality]" ) {
    services::IServiceA service(100);

    service.Set(1, "1");
    service.SetAll("2");
    service.Set(2, "3");
    service.Set(32, "4");

    REQUIRE( service.Get(1) == "2" );
    REQUIRE( service.Get(2) == "3" );
}