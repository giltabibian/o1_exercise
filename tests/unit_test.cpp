#define CATCH_CONFIG_MAIN
#include "test_utils.h"
#include <iostream>
#include <cmath>

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

TEST_CASE_O1( "wraparound", "[functionality]" ) {
    const int maxWrapAroundId = pow(2,8); // uint8_t granularity
    services::IServiceA service(2*maxWrapAroundId);

    service.SetAll("string for all");

    for(size_t i = 0; i < 2*maxWrapAroundId; i++){
        service.Set(i, "string element");
    }
    // service.getAllTimestamp();
    for(size_t i = 0; i < 2*maxWrapAroundId; i++){
        // cout << i << "\n";
        // cout << service.getTimestamp(i) << "\n";
        REQUIRE( service.getTimestamp(i) > service.getAllTimestamp() );
    }
}