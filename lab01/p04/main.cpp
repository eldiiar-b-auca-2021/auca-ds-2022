#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    for (string s; getline(cin, s);)
    {
        string n;
        for (auto &c : s)
        {
            if (isalpha(c))
            {
                n += tolower(c);
            }
        }

        string an = n;
        reverse(an.begin(), an.end());
        if (an == n)
        {
            cout << "palindrome" << endl;
        }
        else
        {
            cout << "not a palindrome" << endl;
        }
        }
}