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
    SUBCASE("int value")
    {
        BigInt x(1234);
        sout << x;
        REQUIRE(sout.str() == "1234");
    }
}
TEST_CASE("addition")
{
    ostringstream sout;
    SUBCASE("positive + positive, #1")
    {
        BigInt x1("12");
        BigInt x2("22");
        sout << x1 + x2;
        REQUIRE(sout.str() == "34");
    }
    // SUBCASE("positive + positive, #2")
    // {

    //     for (int i = 0; i < 1000; i++)
    //     {
    //         for (int j = 0; j < 1000; j++)
    //         {
    //             BigInt x(to_string(i));
    //             BigInt y(to_string(j));
    //             BigInt res = x + y;
    //             sout << res;
    //             REQUIRE(sout.str() == to_string(i + j));
    //             sout.str("");
    //         }
    //     }
    // }

    SUBCASE("positive + positive, #3")
    {
        BigInt x1("9392381283146712389728364726318273724628137");
        BigInt x2("934937491283238127838123894821478218378213");
        BigInt x3 = x1 + x2;
        sout << x3;
        REQUIRE(sout.str() == "10327318774429950517566488621139751943006350");
    }
    SUBCASE("negative + negative, #4")
    {
        BigInt x("-123");
        BigInt y("-234");
        sout << x + y;
        REQUIRE(sout.str() == "-357");
    }
    SUBCASE("positive + negative, #5")
    {
        BigInt x("-123");
        BigInt y("234");
        sout << x + y;
        REQUIRE(sout.str() == "111");
    }
    SUBCASE("positive + negative, #6")
    {
        BigInt x("123");
        BigInt y("-234");
        sout << x + y;
        REQUIRE(sout.str() == "-111");
    }
}

TEST_CASE("subtraction")
{
    ostringstream sout;
    SUBCASE("positive - positive, #1")
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                BigInt x(to_string(i));
                BigInt y(to_string(j));
                sout << x - y;
                REQUIRE(sout.str() == to_string(i - j));
                sout.str("");
            }
        }
    }
    SUBCASE("negative - negative, #2")
    {
        BigInt x1("-9392381283146712389728364726318273724628137");
        BigInt x2("-934937491283238127838123894821478218378213");
        BigInt x3 = x1 - x2;
        sout << x3;
        REQUIRE(sout.str() == "-8457443791863474261890240831496795506249924");
    }
    SUBCASE("negative - positive, #4")
    {
        BigInt x("-123");
        BigInt y("234");
        sout << x - y;
        REQUIRE(sout.str() == "-357");
    }
    SUBCASE("positive - positive, #5")
    {
        BigInt x("123");
        BigInt y("234");
        sout << x - y;
        REQUIRE(sout.str() == "-111");
    }
    SUBCASE("positive - positive, #6")
    {
        BigInt x("323");
        BigInt y("323");
        sout << x - y;
        REQUIRE(sout.str() == "0");
    }
    SUBCASE("positive - negative, #7")
    {
        BigInt x("323");
        BigInt y("-323");
        sout << x - y;
        REQUIRE(sout.str() == "646");
    }
    SUBCASE("positive - negative, #7")
    {
        BigInt x("0");
        BigInt y("4");
        sout << x - y;
        REQUIRE(sout.str() == "-4");
    }
}
TEST_CASE("multiplication")
{
    ostringstream res;
    SUBCASE("100*100")
    {
        BigInt x("100");
        BigInt y("100");
        res << x * y;
        REQUIRE(res.str() == "10000");
    }
}
TEST_CASE("comparisons")
{
    SUBCASE("<")
    {
        BigInt x("244");
        BigInt y("440");
        REQUIRE(x < y);
        BigInt x1("1234");
        BigInt y1("12345");
        REQUIRE(x1 < y1);

        BigInt x2("12");
        BigInt y2("13");
        REQUIRE(x2 < y2);

        BigInt x3("-123");
        BigInt y3("-345");
        REQUIRE(x3 > y3);
    }
    SUBCASE(">")
    {
        BigInt x("244");
        BigInt y("440");
        REQUIRE(y > x);
        BigInt x1("1234");
        BigInt x2("12345");
        REQUIRE(x2 > x1);
        BigInt x3("12");
        BigInt x4("13");
        REQUIRE(x4 > x3);
        BigInt x5("-1234");
        BigInt x6("-2345");
        REQUIRE(x5 > x6);
        BigInt x7("-123");
        BigInt x8("12");
        REQUIRE(x8 > x7);
    }
    SUBCASE("==")
    {
        BigInt x1("1234");
        BigInt x2("1234");
        REQUIRE(x2 == x1);
        BigInt x3("-112");
        BigInt x4("-112");
        REQUIRE(x4 == x3);
    }
    SUBCASE("!=")
    {
        BigInt x1("12347");
        BigInt x2("1234");
        REQUIRE(x2 != x1);
        BigInt x3("-23445");
        BigInt x4("-34");
        REQUIRE(x3 != x4);
    }
}
TEST_CASE("input opearator")
{
    istringstream i("10002002020");
    BigInt x;
    i >> x;
    ostringstream o;
    o << x;
    REQUIRE(o.str() == "10002002020");
    BigInt x2 = 2;
    REQUIRE(x2 == 2);
}
// TEST_CASE("+=")
// {
//     ostringstream o;
//     BigInt x(20);
//     BigInt y(123);
//     x += y;

//     REQUIRE(x == 143);
// }
// TEST_CASE("+=")
// {
//     ostringstream o;
//     BigInt x(20);
//     BigInt y(20);
//     o << x * y;

//     REQUIRE(o.str() == "400");
// }