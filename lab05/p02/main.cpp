#include "../../au/algol.hpp"
#include "VecInt.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

void printVecInt(const VecInt &v);

int main()
{
    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    // Value semantics: copy constructor, assignment operator
    VecInt w = v;
    // w = v;

    reverse(w.begin(), w.end());

    cout << (w == v ? "palindrome" : "not a palindrome") << endl;
}

void printVecInt(const VecInt &v)
{
    for (int e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}
