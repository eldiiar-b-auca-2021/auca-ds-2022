#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>

using namespace std;
template <typename C>
string containerToStr(const C &c)
{
    ostringstream sout;
    sout << "{";
    bool isFirst = true;
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";
    return sout.str();
}
int myAbs(int x)
{
    return x < 0 ? -x : x;
}
TEST_CASE("Default constructor")
{
    vector<int> v;
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}
TEST_CASE("myAbs")
{
    REQUIRE(myAbs(-3) == 3);
    REQUIRE(myAbs(3) == 3);
    REQUIRE(myAbs(0) == 0);
}
TEST_CASE("push_back")
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.capacity() == 8);
}
TEST_CASE("Copy Constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v; // copy constructor

    REQUIRE(v2.size() == 5);
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 5}");
    v[0] = 1000;
    v2[4] = 42;
    REQUIRE(containerToStr(v) == "{1000, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 42}");
}