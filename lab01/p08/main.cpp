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