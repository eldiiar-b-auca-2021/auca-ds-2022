#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <vector>
#include "Rational.hpp"
using namespace std;

TEST_CASE("Default constractor")
{
    const Rational<int> x; // immutable

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);

    for (auto r : v)
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0/1");
}
TEST_CASE("Constractor Rational(num, den)")
{
    SUBCASE("denominator is equal to zero")
    {
        REQUIRE_THROWS_AS(Rational<int>(5, 0), std::runtime_error);
    }
    SUBCASE("reducing 20/10")
    {
        ostringstream sout;
        Rational<int> x(20, 10);
        sout << x;
        REQUIRE(sout.str() == "2/1");
    }
    SUBCASE("reducing 10/25")
    {
        ostringstream sout;
        Rational<int> x(10, 25);
        sout << x;
        REQUIRE(sout.str() == "2/5");
    }
    SUBCASE("reducing 11/17")
    {
        ostringstream sout;
        Rational<int> x(11, 17);
        sout << x;
        REQUIRE(sout.str() == "11/17");
    }
    SUBCASE("reducing 28/-12")
    {
        ostringstream sout;
        Rational<int> x(28, -12);
        sout << x;
        REQUIRE(sout.str() == "-7/3");
    }
    SUBCASE("reducing 6/1")
    {
        ostringstream sout;
        Rational<int> x(6, 1);
        sout << x;
        REQUIRE(sout.str() == "6/1");
    }
}
TEST_CASE("Addition ")
{
    ostringstream sout;
    SUBCASE("1/2 + 2/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(2, 3);
        Rational<int> result = r1 + r2;
        sout << result;
        REQUIRE(sout.str() == "7/6");
    }
    SUBCASE("1/2 + 2")
    {
        Rational<int> r1(1, 2);
        Rational<int> result = r1 + 2;
        sout << result;
        REQUIRE(sout.str() == "5/2");
    }
    SUBCASE("2 + 1/2")
    {
        Rational<int> r1(1, 2);
        Rational<int> result = 2 + r1;
        sout << result;
        REQUIRE(sout.str() == "5/2");
    }
}
TEST_CASE("Rational: substraction")
{
    ostringstream sout;
    SUBCASE("1/2 - 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        Rational<int> result = r1 - r2;
        sout << result;
        REQUIRE(sout.str() == "1/6");
    }
}
TEST_CASE("Rational: multiplication")
{
    ostringstream sout;
    SUBCASE("1/2 * 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        Rational<int> result = r1 * r2;
        sout << result;
        REQUIRE(sout.str() == "1/6");
    }
}
TEST_CASE("Rational: division")
{
    ostringstream sout;
    SUBCASE("1/2 : 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        Rational<int> result = r1 / r2;
        sout << result;
        REQUIRE(sout.str() == "3/2");
    }
    SUBCASE("1/2 : 0/1")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(0, 1);
        REQUIRE_THROWS_AS(r1 / r2, runtime_error);
    }
    SUBCASE("50/3 : 20/2")
    {
        Rational<int> r1(50, 3);
        Rational<int> r2(20, 2);
        sout << r1 / r2;
        REQUIRE(sout.str() == "5/3");
    }
}
TEST_CASE("comparisons")
{
    Rational<int> r1(1, 2);
    Rational<int> r2(1, 3);
    Rational<int> r3(-10, -20);
    REQUIRE(r1 == r3);
    REQUIRE(r1 >= r2);
    REQUIRE(r1 != r2);
}
TEST_CASE("Rational: input operator")
{
    SUBCASE("123/2")
    {
        istringstream sinp("123/2 42");
        Rational<int> r1;
        int x;
        sinp >> r1 >> x;

        ostringstream sout;
        sout << r1;
        REQUIRE(sout.str() == "123/2");
        REQUIRE(x == 42);
    }
}