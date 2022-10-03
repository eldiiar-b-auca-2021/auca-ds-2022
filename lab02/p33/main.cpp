#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int num;
    cin >> num;
    while (num--)
    {
        double size = 0;
        cin >> size;
        vector<double> v(size);
        double sum = 0;
        for (int i = 0; i < sz(v); i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        double average = sum / size;
        double countHigherThanAverage = 0;
        for (int i = 0; i < sz(v); i++)
        {
            if (v[i] > average)
            {
                countHigherThanAverage++;
            }
        }
        double result = (countHigherThanAverage * 100.0) / size;
        cout << fixed << setprecision(3) << result << "%" << endl;
    }
}