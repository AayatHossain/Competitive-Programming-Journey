#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int c, n;
    cin >> c >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<bool>> dp(c + 1, vector<bool>(c + 1, false));
    dp[0][0] = true;
    for (int k = 0; k < n; k++)
    {
        int v = a[k];
        for (int i = c; i >= 0; i--)
        {
            for (int j = c; j >= 0; j--)
            {
                if (!dp[i][j])
                {
                    bool v1 = false, v2 = false;
                    if (i - v >= 0)
                        v1 = dp[i - v][j];
                    if (j - v >= 0)
                        v2 = dp[i][j - v];
                    dp[i][j] = v1 | v2;
                }
            }
        }
    }
    int mi = 0, mj = 0;
    int ms = 0;
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            // cout<<dp[i][j]<<" ";
            if (dp[i][j])
            {
                if (i + j > ms)
                {
                    ms = i + j;
                    mi = i;
                    mj = j;
                }
                else if (i + j == ms)
                {
                    if (abs(i - j) < abs(mi - mj))
                    {
                        mi = i;
                        mj = j;
                    }
                }
            }
        }
        // cout<<endl;
    }
    if (mi >= mj)
    {
        cout << mi << " " << mj << endl;
    }
    else
    {
        cout << mj << " " << mi << endl;
    }
}