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

    vector<BigInt> v(5);
    ostringstream sout2;
    for (const auto &i : v)
    {
        sout2 << i;
    }
    REQUIRE(sout2.str() == "00000");
}
TEST_CASE("Constructor with a string")
{
    ostringstream sout;
    SUBCASE("positive number")
    {
        BigInt x("12344");
        sout << x;
        REQUIRE(sout.str() == "12344");
    }
    SUBCASE("negative number")
    {
        BigInt x("-1234");
        sout << x;
        REQUIRE(sout.str() == "-1234");
    }
    SUBCASE("empty")
    {
        REQUIRE_THROWS_AS(BigInt("  "), runtime_error);
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("invalid number within a string")
    {
        REQUIRE_THROWS_AS(BigInt("1-2399"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("123yzs2923"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("123 123"), runtime_error);
        REQUIRE_THROWS_AS(BigInt("  -123"), runtime_error);
    }
    SUBCASE("+123")
    {
        BigInt x("+123");
        sout << x;
        REQUIRE(sout.str() == "123");
    }
    SUBCASE("00023")
    {
        REQUIRE_THROWS_AS(BigInt("00023"), runtime_error);
    }
}
TEST_CASE("addition")
{
    ostringstream sout;
    SUBCASE("12+23")
    {
        BigInt x1("12");
        BigInt x2("22");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "34");
    }
    SUBCASE("12345678 + 23")
    {
        BigInt x1("12345678");
        BigInt x2("23");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "12345701");
    }
    SUBCASE("23 + 12345678")
    {
        BigInt x1("23");
        BigInt x2("12345678");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "12345701");
    }
    SUBCASE("1234567890 + 987654321")
    {
        BigInt x1("123456789");
        BigInt x2("987654321");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "1111111110");
    }
    SUBCASE("9999 + 8888")
    {
        BigInt x1("-9999");
        BigInt x2("-8888");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "-18887");
    }
    SUBCASE("934937491283238127838123894821478218378213 + 9392381283146712389728364726318273724628137")
    {
        BigInt x1("9392381283146712389728364726318273724628137");
        BigInt x2("934937491283238127838123894821478218378213");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "10327318774429950517566488621139751943006350");
    }
}
TEST_CASE("Substruction")
{
    ostringstream sout;
    SUBCASE("123-114")
    {
        BigInt x1("123");
        BigInt x2("114");
        BigInt x3 = x1 - x2;
        sout << x3;
        REQUIRE(sout.str() == "9");
    }
    SUBCASE("123-23")
    {
        BigInt x1("123");
        BigInt x2("23");
        BigInt res = x1 - x2;
        sout << res;
        REQUIRE(sout.str() == "100");
    }
    SUBCASE("8000-2000")
    {
        BigInt x1("8000");
        BigInt x2("2000");
        sout << x1 - x2;
        REQUIRE(sout.str() == "6000");
    }
    SUBCASE("90090-3200")
    {
        BigInt x1("90090");
        BigInt x2("3200");
        sout << x1 - x2;
        REQUIRE(sout.str() == "86890");
    }
    SUBCASE("7209-229")
    {
        BigInt x1("7208");
        BigInt x2("229");
        sout << x1 - x2;
        REQUIRE(sout.str() == "6979");
    }
    SUBCASE("23-123")
    {
        BigInt x1("23");
        BigInt x2("123");
        BigInt res = x1 - x2;
        sout << res;
        REQUIRE(sout.str() == "-100");
    }
}
// TEST_CASE("comparisons")
// {
//     BigInt x1("1234");
//     BigInt x2("12345");
//     REQUIRE()
// }
