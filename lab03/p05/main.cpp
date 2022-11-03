#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }
using namespace std;
class Computer
{
    vector<int> m;
    vector<int> r;
    int instructionP;

public:
    Computer()
        : m(1000, 0), r(10, 0), instructionP(0)
    {
    }
    void read(std::istream &inp)
    {
        int index = 0;
        char temp;
        for (string i; getline(inp, i) && !i.empty();)
        {

            m[index] = stoi(i);
            index++;
        }
    }
    void print()
    {
        for (int i = 0; i < sz(m); i++)
        {
            cout << m[i] << " ";
        }
    }

    int run()
    {
        int count = 1;
        int index = 0;
        while ((m[index] / 100) != 1)
        {
            int d;
            int n;
            int temp;
            temp = (m[index] % 10);
            n = temp;
            temp /= 10;
            d = temp % 10;
            temp /= 10;

            switch (temp)
            {
            case 2:
                r[d] = n;
                break;
            case 3:
                r[d] += n;
                r[d] %= 1000;
                break;
            case 4:
                r[d] *= n;
                r[d] %= 1000;
                break;
            case 5:
                r[d] = r[n];
                break;
            case 6:
                r[d] += r[n];
                r[d] %= 1000;
                break;
            case 7:
                r[d] *= r[n];
                r[d] %= 1000;
                break;
            case 8:
                r[d] = m[r[n]];
                break;
            case 9:
                m[r[n]] = r[d];
                break;
            case 0:
                if (r[n] != 0)
                {
                    index = r[d];
                }
                break;
            }
            count++;
            index++;
        }
        return count;
    }
};

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n >> ws;
    for (int i = 0; i < n; i++)
    {
        Computer c;
        c.read(cin);
        c.print();
        cout << c.run() << endl;
    }
}