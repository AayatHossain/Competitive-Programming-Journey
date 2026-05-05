#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31;

int fact[20];
int dp[31][31];

int f(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    if (r == 1)
        return n;
    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = f(n - 1, r) + f(n - 1, r - 1);
}

signed main()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 20; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    memset(dp, -1, sizeof dp);

    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        if (k > n)
        {
            cout << "Case " << c << ": " << 0 << endl;
            c++;
            continue;
        }
        int v = f(n, k);
        int ans = v * v * fact[k];
        cout << "Case " << c << ": " << ans << endl;
        c++;
    }
    return 0;
}