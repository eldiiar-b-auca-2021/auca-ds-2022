#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    string text;

    string currentS;
    getline(cin, text);

    vector<string> str;

    for (int i = 0; i < (int)text.size(); i++)
    {
        if (text.at(i) != ' ')
        {
            currentS += text.at(i);
        }
        else
        {
            str.push_back(currentS);
            currentS = "";
        }
    }
    str.push_back(currentS);
    currentS = "";
    bool isVowel = false;
    for (int i = 0; i < (int)str.size(); i++)
    {
        string temp = str[i];
        switch (temp.at(0))
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
            isVowel = true;
        }
        if (isVowel)
        {
            if (temp.at(temp.size() - 1) != '.')
            {
                currentS += temp;
                currentS += "ay";
                currentS += " ";
            }
            else
            {
                currentS += temp.substr(0, temp.size() - 1);
                currentS += "ay";
                currentS += ".";
            }
        }
        else
        {
            currentS += temp.substr(1, temp.size());
            currentS += temp.substr(0, 1);
            currentS += "ay";
            currentS += " ";
        }
        isVowel = false;
        cout << currentS;
        currentS = "";
        if (((int)str.size() - 1) == i)
        {
            cout << endl;
        }
    }
}