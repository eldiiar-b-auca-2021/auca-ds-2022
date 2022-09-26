#include <bits/stdc++.h>
#include <string>
#include <algorithm>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    for (string text; getline(cin, text);)
    {

        string newS;
        string currentText;
        string res;

        for (int i = 0; i < (int)text.size(); i++)
        {

            if (text.at(i) != ' ')
            {
                currentText += text.at(i);
            }
            else
            {
                reverse(currentText.begin(), currentText.end());
                res += currentText;
                res += " ";
                currentText = "";
            }
        }
        reverse(currentText.begin(), currentText.end());
        res += currentText;
        cout << res << "\n";
        cin.clear();
    }
}