#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Project/class/IPSplitter.cpp"

using namespace std;

TEST_CASE("Splitter test", "[ipStringToArray]") {
    IPSplitter splitter;
    const char* string = "123.231.1.2";
    int numbers [4];
    splitter.ipStringToArray(numbers,string);
    REQUIRE(numbers[0] == 123);
    REQUIRE(numbers[1] == 231);
    REQUIRE(numbers[2] == 1);
    REQUIRE(numbers[3] == 2);
}