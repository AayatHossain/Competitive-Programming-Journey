#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    memset(dp, 0, sizeof dp);
    
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int v = INT_MAX;
            if (i == j)
            {
                v = 0;
            }
            else
            {
                for (int k = 1; k < i; k++)
                {
                    v = min(v, 1 + dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++)
                {
                    v = min(v, 1 + dp[i][k] + dp[i][j - k]);
                }
            }
            dp[i][j] = v;
        }
    }
    cout << dp[a][b] << endl;
}