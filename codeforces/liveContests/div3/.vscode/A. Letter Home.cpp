#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (s < a[0])
        {
            cout << (a[0] - s) + (a[n-1] - a[0]) << endl;
        }
        else if (s > a[n - 1])
        {
            cout << (s - a[n - 1]) + (a[n-1] - a[0]) << endl;
        }
        else
        {
            int v1 = abs(s - a[0]);
            int v2 = abs(s - a[n - 1]);
            int res = 0;
            if (v1 < v2)
            {
                res = 2 * v1 + v2;
            }
            else
            {
                res = 2 * v2 + v1;
            }
            cout << res << endl;
        }
    }
    return 0;
}