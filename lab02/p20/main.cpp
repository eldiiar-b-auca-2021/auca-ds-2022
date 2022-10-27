#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    // while (EOF)
    // {
    for (int n; cin >> n;)
    {

        vector<string> v(n);
        vector<int> people(n, 0);
        vector<int> peopleThatGet(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            string man;
            cin >> man;
            int money;
            cin >> money;
            int numOfPeople;
            cin >> numOfPeople;
            for (int j = 0; j < sz(v); j++)
            {
                if (v[j] == man)
                {
                    if (numOfPeople != 0)
                        people[j] = money - (money % numOfPeople);
                }
            }
            if (numOfPeople != 0)
            {
                int howMuch = money / numOfPeople;
                for (int j = 0; j < numOfPeople; j++)
                {
                    string name;
                    cin >> name;
                    for (int k = 0; k < sz(v); k++)
                    {
                        if (v[k] == name)
                        {
                            peopleThatGet[k] += howMuch;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < sz(people); i++)
        {
            cout << v[i] << " " << peopleThatGet[i] - people[i] << endl;
        }
        cout << endl;
    }
}
