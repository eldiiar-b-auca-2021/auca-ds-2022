#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    int count = 0;
    while (n--)
    {
        count++;
        vector<string> url;
        vector<int> num;
        for (int i = 0; i < 10; i++)
        {
            string temp = "";
            cin >> temp;
            url.push_back(temp);
            int v = 0;
            cin >> v;
            num.push_back(v);
        }
        int max = 0;
        for (int i = 0; i < 10; i++)
        {
            if (num[i] > max)
            {
                max = num[i];
            }
        }
        cout << "Case #" << count << ":" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (max == num[i])
            {
                cout << url[i] << endl;
            }
        }
    }
}