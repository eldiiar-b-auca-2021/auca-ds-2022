// #include "../../au/algol.hpp"

#include "VecInt.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void p01();
void p02();
void printVecInt(const VecInt &v);

int main()
try
{
    p01();
    // p02();

    // VecInt x(5);
    // cout << x[6] << endl;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
}

void p01()
{
    cout << "size of array: ";

    int n;
    cin >> n;

    VecInt v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // auReverse(v.begin(), v.end());

    printVecInt(v);
}

void p02()
{
    cout << "enter integer numbers:" << endl;

    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printVecInt(v);
    // /auReverse(v.begin(), v.end());
    printVecInt(v);
}

void printVecInt(const VecInt &v)
{
    // also works
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << "\n";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
