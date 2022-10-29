#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
bool isVowel(char &ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }
    return false;
}
int main()
{
    iostream::sync_with_stdio(false);
    string text;

    getline(cin, text);

    vector<string> str;
    string temp;

    for (int i = 0; i < sz(text); i++)
    {
        if (text[i] != ' ')
        {
            temp += text[i];
        }
        else
        {
            str.push_back(temp);
            temp = "";
        }
    }
    str.push_back(temp);
    for (int i = 0; i < sz(str); i++)
    {
        if (isVowel(str[i].at(0)))
        {
            string t;
            if (str[i].at(str[i].size() - 1) != '.')
            {
                t = str[i] + "ay";
                str[i] = t;
            }
            else
            {
                t = str[i].substr(0, str[i].size() - 1) + "ay.";
                str[i] = t;
            }
        }
        else
        {
            string t;
            if (str[i].at(str[i].size() - 1) != '.')
            {
                t = str[i].substr(1, str[i].size() - 1) + str[i].at(0);
                t += "ay";
                str[i] = t;
            }
            else
            {
                t = str[i].substr(1, str[i].size() - 1) + str[i].at(0);
                t += "ay.";
                str[i] = t;
            }
        }
    }
    for (int i = 0; i < sz(str); i++)
    {
        cout << str[i];
        if (i != sz(str))
        {
            cout << " ";
        }
    }
    cout << endl;
}