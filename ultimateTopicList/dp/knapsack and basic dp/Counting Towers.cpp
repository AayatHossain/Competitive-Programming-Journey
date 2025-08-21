#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e6+1;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> dp(N + 1, vector<int>(3));
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][1] = (((4 * (dp[i - 1][1] % mod)) % mod) + dp[i - 1][2] % mod) % mod;
        dp[i][2] = (((2 * (dp[i - 1][2] % mod)) % mod) + dp[i - 1][1] % mod) % mod;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][1] % mod + dp[n][2] % mod) % mod << '\n';
    }
    return 0;
}