#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (string s; getline(cin, s);)
    {
        string n;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                n += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                n += (char)s[i] + 32;
            }
        }
        string an;
        for (int i = (int)n.size() - 1; i >= 0; i--)
        {
            an += n[i];
        }
        if (an == n)
        {
            cout << "palindrome" << endl;
        }
        else
        {
            cout << "not a palindrome" << endl;
        }
        // cout << n << " " << an << endl;
    }
}