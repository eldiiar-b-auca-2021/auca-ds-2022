#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

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
void example01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << (containerToStr(v) == "{1, 2, 3, 4}" ? "Ok\n" : "Error\n");
}
vector<string> split(const string &s)
{
    vector<string> res;
    istringstream sinp(s);
    for (string w; sinp >> w;)
    {
        res.push_back(w);
    }
    return res;
}
void example02()
{
    vector<string> res = split("Hello WOrld !!!");
    cout << res.size() << endl;
}
bool isInt(const string &s)
{
    istringstream sinp(s);
    int x;
    char c;
    return sinp >> x && !(sinp >> c);
}
void example03()
{
    cout << boolalpha;
    cout << isInt("  123  ") << endl;
    cout << isInt("   123u ") << endl;
}
int main()
{
    iostream::sync_with_stdio(false);
    example01();
    example02();
    example03();
}