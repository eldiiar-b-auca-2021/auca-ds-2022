#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
struct Freq
{
    char letter;
    int count;
    Freq(const char l, const int c)
        : letter(l), count(c)
    {
    }
};
int main()
{
    iostream::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        vector<int> alphabet(26);
        int row, col, minByte, maxByte;
        cin >> row;
        cin >> col;
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                char ch;
                cin >> ch;
                int value = (int)ch - 'A';
                alphabet[value]++;
            }
        }
        vector<Freq> vect;
        for (int j = 0; j < 26; j++)
        {
            char temp = (char)j + 65;
            vect.emplace_back(temp, alphabet[j]);
        }
        sort(begin(vect), end(vect), [](Freq &f, Freq &s)
             { return f.count > s.count; });
        int max = 0;
        for (int j = 0; j < 26; j++)
        {
            if (max < vect[j].count)
            {
                max = vect[j].count;
            }
        }
        int sum = 0;
        for (int j = 0; j < 26; j++)
        {
            if (max == vect[j].count)
            {
                sum += maxByte * vect[j].count;
            }
            else
            {
                sum += minByte * vect[j].count;
            }
        }
        cout << "Case " << (i + 1) << ": " << sum << endl;
    }
}