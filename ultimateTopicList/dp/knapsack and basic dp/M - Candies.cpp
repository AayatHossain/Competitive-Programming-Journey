#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dp[n][k + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= a[0]; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> pref(k + 1);
        pref[0] = dp[i - 1][0]%mod;
        for (int z = 1; z <= k; z++)
        {
            pref[z] = (pref[z - 1]%mod + dp[i - 1][z]%mod)%mod;
        }
        for (int j = 0; j <= k; j++)
        {
            if (j - a[i] - 1 >= 0)
            {
                dp[i][j] = (pref[j] - pref[j - a[i] - 1] + mod)%mod;
            }
            else
            {
                dp[i][j] = pref[j]%mod;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout << dp[n - 1][k]%mod << endl;
    return 0;
}