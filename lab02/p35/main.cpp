#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int index;
    string s;
    getline(cin, s);
    for (int j = 0; j < (int)s.length(); j++)
    {
        char ch = s[j];
        if (ch == ' ')
        {
            cout << " ";
        }
        else
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;
            }
            index = keyboard.find(ch);
            if (index - 2 >= 0)
            {
                index -= 2;
            }
            else
            {
                index -= 2;
                index += 47;
            }
            ch = keyboard.at(index);
            cout << ch;
        }
    }
    cout << "\n";
}