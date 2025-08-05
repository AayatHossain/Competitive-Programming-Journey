#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
int n, m;
int a[N];
int dp[N][101];
int f(int prev, int i)
{
    if ((prev <= 0 || prev > m) && prev != -1)
        return 0;
    if (i > n)
        return 1;
    if (dp[i][prev] != -1)
        return dp[i][prev];
    if (a[i] != 0)
    {
        if (abs(a[i] - prev) <= 1)
        {
            return dp[i][prev] = f(a[i], i + 1) % mod;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int v = 0;
        if (prev == -1)
        {
            for (int j = 1; j <= m; j++)
            {

                v = (v%mod + f(j, i + 1)%mod)%mod;
            }
        }
        else
        {
            int v1 = f(prev+1, i+1)%mod;
            int v2 = f(prev, i+1)%mod;
            int v3 = f(prev-1, i+1)%mod;
            v = ((v1+v2)%mod + v3)%mod;
        }
        return dp[i][prev] = v;
    }
}
signed main()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int prev;
    if(a[1]==0){
        prev = -1;
    }else{
        prev = a[1];
    }
    ans = f(prev, 1)%mod;
    cout << ans % mod << endl;
    return 0;
}