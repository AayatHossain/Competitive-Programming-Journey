#include <bits/stdc++.h>
using namespace std;
#define int long long

void calcPow(vector<int> &a, int n, vector<int> &two, vector<int> &five)
{
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        while (x % 2 == 0 && x != 0)
        {
            two[i]++;
            x /= 2;
        }
        while (x % 5 == 0 && x != 0)
        {
            five[i]++;
            x /= 5;
        }
    }
    return;
}

signed main()
{

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> two(n, 0);
    vector<int> five(n, 0);
    calcPow(a, n, two, five);
    int p5 = 0;
    for (int x : five)
        p5 += x;

    int dp[2][k + 1][p5 + 1];
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l <= p5; l++)
            {
                int curr = (i&1);
                int next = !curr;
                if (dp[curr][j][l] == -1)
                    continue;

                dp[next][j][l] = max(dp[next][j][l], dp[curr][j][l]);

                if (l + five[i] > p5 || j + 1 > k)
                {
                    continue;
                }

                dp[next][j + 1][l + five[i]] = max(dp[curr][j][l] + two[i], dp[next][j + 1][l + five[i]]);
            }
        }
    }
    int ans = LLONG_MIN;

    for (int l = 0; l <= p5; l++)
    {
        if (dp[n&1][k][l] != -1)
        {
            ans = max(ans, min(dp[n&1][k][l], l));
        }
    }

    cout << ans << endl;

    return 0;
}