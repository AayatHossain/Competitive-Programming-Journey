#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
signed main()
{
    
    int t;
    cin >> t;
    int tc = 1;

    while (t--)
    {
        int n;
        cin >> n;
        int ans = 1;
        // map<int, int> m;
        set<int> s;
        for (int i = 2; i * i <= n; i++)
        {
            int v = i;
            if (n > 0 && n % i == 0)
            {
                s.insert(i);
                while (n > 0 && n % i == 0)
                {
                    n /= i;
                }
            }
        }
        if(n > 0 )s.insert(n);
        for (auto x : s)
        {
            ans *= x;
        }
        cout << ans << endl;
    }
    return 0;
}