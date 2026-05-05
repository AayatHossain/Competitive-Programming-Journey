#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> m;
        int ans = 0;
        sort(a.begin(), a.end());
        int c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                c1++;
                continue;
            }
            int v = n / a[i];
            v = v * a[i];
            if (v > 0 && v <= n)
            {
                m[v]++;
                ans = max(ans, m[v]);
            }
        }
        
        ans += c1;
        cout << ans << endl;
    }
    return 0;
}