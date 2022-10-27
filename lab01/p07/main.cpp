#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include "string"

using namespace std;

TEST_CASE("default constructor")
{
    string n;
    REQUIRE(n.empty() == true);
    REQUIRE(n.size() == 0);
}
TEST_CASE("constructor with size and intial value")
{
    string str(4, 'i');
    REQUIRE(str.at(3) == 'i');
    REQUIRE(str.size() == 4);
}
TEST_CASE("copy constructor")
{
    string str = "string";
    string str2 = str;
    REQUIRE(str == str2);
}
TEST_CASE("at(index), exception")
{
    string str = "string";
    REQUIRE_THROWS_AS(str.at(9), std::logic_error);
}
TEST_CASE("push_back()")
{
    string str;
    str.push_back('a');
    REQUIRE(str.at(0) == 'a');
}
TEST_CASE("pop_back()")
{
    string str = "string";
    str.pop_back();
    REQUIRE(str.back() == 'n');
}
TEST_CASE("+, += operators")
{
    string str;
    str += 's';
    str += 't';
    str += 'r';
    REQUIRE(str == "str");
    string str2 = "ing";
    str = str + str2;
    REQUIRE(str == "string");
}
TEST_CASE("==, !=, <")
{
    string str = "string";
    string str2 = "string";
    string str3 = "is not a string";
    REQUIRE(str == str2);
    REQUIRE(str3 != str2);
    REQUIRE(str.size() < str3.size());
}
TEST_CASE("(auto &c : str)")
{
    string str = "string";
    string str2;
    for (auto &c : str)
    {
        str2 += c;
    }
    REQUIRE(str == str2);
}
TEST_CASE("front(), back()")
{
    string str = "string";
    REQUIRE(str.front() == 's');
    REQUIRE(str.back() == 'g');
}
TEST_CASE("substr(index, length), find(char ch)")
{
    string str = "string";
    REQUIRE(str.substr(0, 2) == "st");
    string str2 = "s";
    size_t found = str.find(str2);
    REQUIRE(found == 0);
}
TEST_CASE("insert(index, length, char")
{
    string str = "string";
    str.insert(6, 3, 'g');
    REQUIRE(str == "stringggg");
}
TEST_CASE("erase(index, length)")
{
    string str = "string";
    str.erase(3, 3);
    REQUIRE(str == "str");
}
TEST_CASE("move constructor")
{
    string str = "string";
    string *anStr = &str;
    REQUIRE(str == *anStr);
}
TEST_CASE("constructor string(beg, end)")
{
    string str = "string";
    str.erase(str.begin(), str.end());
    REQUIRE(str == "");
}
TEST_CASE("std::reverse algorithm with std::string")
{
    string str = "string";
    reverse(str.begin(), str.end());
    REQUIRE(str == "gnirts");
}
TEST_CASE("std::sort algorithm with std::string")
{
    string str = "string";
    sort(str.begin(), str.end());
    REQUIRE(str == "ginrst");
}
TEST_CASE("std::max_element algorithm with std::string")
{
    string str = "string";
    sort(str.begin(), str.end());
    REQUIRE(*max_element(str.begin(), str.end()) == 't');
}
TEST_CASE("std::min_element algorithm with std::string")
{
    string str = "string";
    sort(str.begin(), str.end());
    REQUIRE(*min_element(str.begin(), str.end()) == 'g');
}
TEST_CASE("subscript operator")
{
    string str = "string";
    REQUIRE(str[0] == 's');
}