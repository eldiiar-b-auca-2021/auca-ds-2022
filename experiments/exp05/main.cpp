#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int num = 8;
    int *anotherNameOf_Num = &num;
    if (num == *anotherNameOf_Num)
    {
        cout << "Yes" << endl;
    }
    *anotherNameOf_Num = 10;
    cout << num << " " << anotherNameOf_Num << endl;
    string str = "string";
    string anStr = "double";
    sort(str.begin(), str.end());
    cout << *max_element(str.begin(), str.end()) << *max_element(anStr.begin(), anStr.end()) << endl;
    cout << *binary_search(str.begin(), str.end(), "t") << endl;
}