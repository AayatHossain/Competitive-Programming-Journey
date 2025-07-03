#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans;
        if (n & 1)
        {
            int d = (n - 1) / 2;
            int v = k + (k - 1) / d;
            if (v % n == 0)
            {
                ans = n;
            }
            else
            {
                ans = v % n;
            }
        }else{
            if (k % n == 0)
            {
                ans = n;
            }
            else
            {
                ans = k % n;
            }
        }

        cout << ans << endl;
    }
    return 0;
}