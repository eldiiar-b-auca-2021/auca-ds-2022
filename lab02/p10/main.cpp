#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        int high = 0;
        int low = 0;
        int first;
        // vector<int> v(size);
        cin >> first;
        for (int j = 1; j < size; j++)
        {
            int num;
            cin >> num;
            if (num > first)
            {
                high++;
            }
            else if (num < first)
            {
                low++;
            }
            first = num;
        }
        cout << "Case " << (i + 1) << ": " << high << " " << low << "\n";
    }
}