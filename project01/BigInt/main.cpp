#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <sstream>
#include "../../doctest/doctest.h"
#include "BigInt.hpp"
using namespace std;
TEST_CASE("default constructor")
{

    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");
}
TEST_CASE("Non-digit value")
{
    REQUIRE_THROWS_AS(BigInt("123vc"), runtime_error);
    REQUIRE_THROWS_AS(BigInt("  "), runtime_error);
}
