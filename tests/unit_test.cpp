#define CATCH_CONFIG_MAIN
#include "test_utils.h"
#include <iostream>
#include <cmath>
#include <chrono>

#include "src/services/IServiceA.h"

using std::cout;
using namespace std::chrono;

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

TEST_CASE_O1( "timing", "[functionality]" ) {
    services::IServiceA service1(1);
    services::IServiceA service2(10000000);

    auto service1Start = high_resolution_clock::now();
    for(size_t i = 0; i < 10000; i++){
        service1.SetAll("string for all");
    }
    auto service1End = high_resolution_clock::now();
    auto service1Time = duration_cast<milliseconds>(service1End - service1Start).count();

    auto service2Start = high_resolution_clock::now();
    for(size_t i = 0; i < 10000; i++){
        service2.SetAll("string for all");
    }
    auto service2End = high_resolution_clock::now();
    auto service2Time = duration_cast<milliseconds>(service2End - service2Start).count();

    // cout << service2Time << "\n";

    REQUIRE( service1Time == service2Time );

}