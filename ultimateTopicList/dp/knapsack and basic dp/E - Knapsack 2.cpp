#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    vector<int> b(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cin >> a[i];
        s += a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, LLONG_MAX));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= 1; j--)
        {
            if (j - a[i-1] >= 0)
            {
                int v1 = dp[i - 1][j - a[i - 1]];
                int v2 = dp[i - 1][j];
                if(v1 != LLONG_MAX && v1 + b[i-1] <= w){
                    v1 = v1 + b[i-1];
                    dp[i][j]= min(v1,v2);
                }else{
                    dp[i][j]=v2;
                }
            }
            else
            {
                for (int j = a[i-1] - 1; j >= 1; j--)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for(int j = s; j >= 0; j--){
        for(int i = 0; i <= n; i++){
            if(dp[i][j] != LLONG_MAX){
                ans = j;
                break;
            }
        }
        if(ans != 0){
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}