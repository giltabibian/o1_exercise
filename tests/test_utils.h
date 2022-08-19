#pragma once

#include "catch.h"

#include <cmath>
#include <future>
#include <thread>
#include <iostream>

#define CONCAT_IMPL(X, Y) X##Y
#define CONCAT(X, Y) CONCAT_IMPL(X, Y)
#define TESTROOT_FUNCNAME CONCAT(TESTROOT_, __LINE__)
#define TEST_FUNCNAME CONCAT(TEST_, __LINE__)
#define TEST_CASE_O1(TestName, ...)               \
    static inline void TESTROOT_FUNCNAME();    \
    static inline void TEST_FUNCNAME();        \
    TEST_CASE(TestName, __VA_ARGS__) {            \
        TESTROOT_FUNCNAME();                   \
    }                                             \
    static inline void TESTROOT_FUNCNAME() {   \
        std::cout << "Running test " << TestName << "\n";  \
        TEST_FUNCNAME();                       \
        std::cout << "Finished test " << TestName << "\n"; \
    }                                             \
    static inline void TEST_FUNCNAME()
