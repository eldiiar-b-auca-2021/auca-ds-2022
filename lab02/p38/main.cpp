#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    for (string s; cin >> s;)
    {
        string current;
        for (int i = 0; i < (int)s.size(); i++)
        {
            switch (s.at(i))
            {
            case 'A':
            case 'B':
            case 'C':
                current += '2';
                break;
            case 'D':
            case 'E':
            case 'F':
                current += '3';
                break;
            case 'G':
            case 'H':
            case 'I':
                current += '4';
                break;
            case 'J':
            case 'K':
            case 'L':
                current += '5';
                break;
            case 'M':
            case 'N':
            case 'O':
                current += '6';
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                current += '7';
                break;
            case 'T':
            case 'U':
            case 'V':
                current += '8';
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                current += '9';
                break;
            default:
                current += s.at(i);
            }
        }
        cout << current << endl;
        current = "";
    }
}