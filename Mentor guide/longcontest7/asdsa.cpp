#include <bits/stdc++.h>
using namespace std;
int f(int &s, int cs, int i, int n, vector<vector<int>> &dp, vector<int> &arr)
{
    if (cs == s - cs)
    {
        // cout<<i<<" "<<cs<<endl;
        return 1;
    }
    if (cs > s - cs || cs == s || i >= n)return 0;
    // cout<<cs<<" "<<s<<endl;

    if (dp[cs][i] != -1)
        return dp[cs][i];
    int v1 = f(s, cs + arr[i], i + 1, n, dp, arr);
    int v2 = f(s, cs, i + 1, n, dp, arr);
    return dp[cs][i] = (v1 | v2);
}

bool equalPartition(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    vector<vector<int>> dp(sum + 1, vector<int>(n, -1));
    int ans = f(sum, 0, 0, n, dp, arr);
    // cout<<ans<<endl;
    return ans;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << equalPartition(a) << endl;
    return 0;
}