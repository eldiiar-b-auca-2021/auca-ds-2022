#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int nu;
    cin >> nu;
    vector<int> reg(10, 0);
    vector<int> mem;
    for (int i = 0; i < nu; i++)
    {
        for (int s; cin >> s;)
        {
            mem.push_back(s);
        }
    }
    int i = 0;
    int count = 0;
    while (1)
    {
        int d, n;
        int temp = 2;
        int r = mem[i];
        n = r % 10;
        count++;
        int isBreak = r / 100;
        if (isBreak == 1)
        {
            break;
        }
        while (temp--)
        {
            d = r % 10;
            r /= 10;
        }
        i++;

        switch (isBreak)
        {
        case 2:
            reg[d] = n;
            break;
        case 3:
            reg[d] += n;
            reg[d] %= 1000;
            break;
        case 4:
            reg[d] *= n;
            reg[d] %= 1000;
            break;
        case 5:
            reg[d] = reg[n];
            reg[d] %= 1000;
            break;
        case 6:
            reg[d] += reg[n];
            reg[d] %= 1000;
            break;
        case 7:
            reg[d] *= reg[n];
            reg[d] %= 1000;
            break;
        case 8:
            reg[d] = mem[reg[n]];
            break;
        case 9:
            mem[reg[n]] = reg[d];
            break;
        case 0:
            if (reg[n] != 0)
                i = reg[d];
            break;
        }
    }
    cout << count << endl;
}