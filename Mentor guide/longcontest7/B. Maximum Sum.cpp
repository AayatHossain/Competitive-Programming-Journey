#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = LLONG_MIN / 2;
        sort(a.begin(), a.end());
        vector<int> p(n);
        p[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            p[i] = p[i - 1] + a[i];
        }

        for (int i = 0; i <= k; i++)
        {
            int left, right;

            if (i == 0)
            {
                left = 0;
            }
            else
            {
                left = p[2 * i - 1];
            }
            right = p[n - (k - i) - 1];

            // cout<<right<<" "<<left<<endl;
            ans = max(ans, right - left);
        }
        cout << ans << endl;
    }
}