#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        sort(a.begin(), a.end());
        if (a.size() == 2)
        {
            cout << max(a[0], a[1] - a[0]) << endl;
        }
        else
        {
            int ans = INT_MIN;
            for (int i = 1; i < n; i++)
            {
                ans = max(ans, a[i] - a[i - 1]);
            }
            if (ans == INT_MIN)
            {
                cout << a[0] << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}