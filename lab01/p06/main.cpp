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
TEST_CASE("back(), front()")
{
    vector<int> v;
    vector<int> av(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int i = 0;
    for (auto &e : v)
    {
        av[i++] = e;
    }
    REQUIRE(v.back() == av.back());
    REQUIRE(v.front() == av.front());
}
TEST_CASE("pop_back()")
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    REQUIRE(v.size() == 2);
}
TEST_CASE("operator [] (index)")
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v[2] = 4;
    REQUIRE(v[0] == 1);
    REQUIRE(v[2] == 4);
}
TEST_CASE("insert(it)")
{
    vector<int> num = {1, 3, 2, 4};
    vector<int>::iterator it;
    it = num.begin();

    num.insert(it, 100);
    REQUIRE(containerToStr(num) == "{100, 1, 3, 2, 4}");
}
TEST_CASE("insert(it, beg, end)")
{
    vector<int> v = {5, 6, 7, 2, 4};
    vector<int>::iterator it;
    v.insert(v.begin(), 2, 2);
    REQUIRE(containerToStr(v) == "{2, 2, 5, 6, 7, 2, 4}");
}
TEST_CASE("at()")
{
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    REQUIRE_THROWS_AS(v.at(10), std::logic_error);
}
TEST_CASE("erase(it)")
{
    vector<int> num = {1, 3, 2, 4};
    vector<int>::iterator it;
    it = num.begin();
    num.erase(it);
    REQUIRE(containerToStr(num) == "{3, 2, 4}");
}
TEST_CASE("erase(beg, end)")
{
    vector<int> num = {1, 3, 2, 4};
    num.erase(num.begin(), num.end());
    REQUIRE(num.size() == 0);
}
TEST_CASE("reverse")
{
    vector<int> num = {1, 3, 2, 4};
    reverse(num.begin(), num.end());
    REQUIRE(containerToStr(num) == "{4, 2, 3, 1}");
}
TEST_CASE("sort")
{
    vector<int> num = {1, 3, 2, 4};
    sort(num.begin(), num.end());
    REQUIRE(containerToStr(num) == "{1, 2, 3, 4}");
}
TEST_CASE("binary_search")
{
    int n = 2;
    vector<int> num = {1, 2, 3, 4};
    int search = 0;
    if (binary_search(num.begin(), num.end(), n))
    {
        search = 2;
    }
    REQUIRE(n == search);
}
TEST_CASE("min_element, max_element")
{
    vector<int> num = {1, 2, 3, 4};
    vector<int>::iterator result;
    result = min_element(num.begin(), num.end());
    REQUIRE(*result == 1);
    vector<int> n = {1, 6, 2, 34};
    vector<int>::iterator max;
    max = max_element(n.begin(), n.end());
    REQUIRE(*max == 34);
}
TEST_CASE("vector(beg, end)")
{
    vector<int> v = {5, 2, 1, 3, 4};
    v.erase(v.begin(), v.end());
    REQUIRE(containerToStr(v) == "{}");
}
TEST_CASE("constructor with size and initial value")
{
    vector<int> v(5, 2);
    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 2);
}
TEST_CASE("std::vector<int>::iterator, operators: *it, it->field , ++it, --it, it += n, it-=n, it2 – it1")
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator n;
    ostringstream s;
    s << "{";
    for (n = v.begin(); n != v.end() - 1; n++)
    {
        s << *n << ", ";
    }
    s << v.back() << "}";
    REQUIRE(containerToStr(v) == s.str());

    ostringstream s2;
    vector<int>::iterator n2;
    s2 << "{";
    for (n2 = v.end() - 1; n2 != v.begin(); n2--)
    {
        s2 << *n2 << ", ";
    }
    s2 << v.front() << "}";
    reverse(v.begin(), v.end());
    REQUIRE(containerToStr(v) == s2.str());
}
