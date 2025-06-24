#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
vector<int> a(N);
int n;
int dp[N][N][2];
int f(int l, int r, int t)
{
    if (l > r)
        return 0;
    if (dp[l][r][t] != -1)
        return dp[l][r][t];
    if (t == 0)
    {
        int temp = 0;
        int score1 = LLONG_MIN / 2;
        int score2 = LLONG_MIN / 2;
        for (int j = l; j <= r; j++)
        {
            temp += a[j];
            int tscore = temp + f(j + 1, r, !t);
            score1 = max(score1, tscore);
        }
        temp = 0;
        for (int j = r; j >= l; j--)
        {
            temp += a[j];
            int tscore = temp + f(l, j - 1, !t);
            score2 = max(score2, tscore);
        }
        return dp[l][r][t] = max(score1, score2);
    }
    else
    {
        int temp = 0;
        int score1 = LLONG_MAX / 2;
        int score2 = LLONG_MAX / 2;
        for (int j = l; j <= r; j++)
        {
            temp += a[j];
            int tscore = -temp + f(j + 1, r, !t);
            score1 = min(score1, tscore);
        }
        temp = 0;
        for (int j = r; j >= l; j--)
        {
            temp += a[j];
            int tscore = -temp + f(l, j - 1, !t);
            score2 = min(score2, tscore);
        }
        return dp[l][r][t] = min(score1, score2);
    }
}
signed main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        string s;
        getline(cin, s);
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        int ans = f(0, n - 1, 0);
        cout<<"Case "<<c<<": "<<ans<<endl;
        c++;
    }
    return 0;
}