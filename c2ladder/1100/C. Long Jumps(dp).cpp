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
        vector<int> dp(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mx = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            int v;
            if (dp[i] != -1)
            {
                v = dp[i] + a[i];
            }
            else
            {
                v = a[i];
            }
            int index = i + a[i];
            if(index >= n){
                index = n;
            }
            if (dp[index] < v)
            {
                dp[index] = v;
            }
            //asdasd
            mx = max(mx, dp[index]);
        }
        cout<<mx<<endl;
    }
    return 0;
}