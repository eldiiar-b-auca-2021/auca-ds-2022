#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int solve(int a, int b){
    if (a > b){
        swap(a, b);
    }
    int cur;
    
    int res = 0;
    for (int i = a; i <= b; i++){
        cur = i;
        int length = 1;
        while(cur != 1){
            length++;
            cur = cur % 2 == 0 ? cur / 2 : cur * 3 + 1;
        }   
        res = max(length,res);
    }
    return res;
}
int main()
{
    iostream::sync_with_stdio(false);

    for (int a, b; cin >> a >> b;){
        cout << a << " " << b << " " << solve(a, b) << endl;
    }
}