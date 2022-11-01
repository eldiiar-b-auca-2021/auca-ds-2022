#include <bits/stdc++.h>
#include <stdexcept>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    istringstream inp("1 /2");
    int num;
    if (!(inp >> num))
    {
        cout << num << " "
             << "is written" << endl;
    }
    cout << num << endl;
    char ch;
    if (!(inp.get(ch)))
    {
        cout << "There is not a gap" << endl;
    }
    if (!(inp.get(ch)))
    {
        inp.putback(ch);
    }
    if (ch != '/')
    {
        cout << ch << endl;
    }
    if (!(inp.get(ch)))
    {
        cout << ch << endl;
    }
    if (ch == '+' || ch == '-' || isdigit(ch))
    {
        inp.putback(ch);
    }
    int n;
    inp >> n;
    cout << n << endl;
}