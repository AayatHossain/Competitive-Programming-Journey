#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int i, int k, vector<vector<int>> &dp, vector<int> & c, int n){
    if(i>=n || k == 0)return 0;
    if(dp[i][k]!= -1)return dp[i][k];
    int v1 = c[i] + f(i+1, k-1, dp, c, n);
    int v2 = f(i+1, k, dp, c, n);
    return dp[i][k] = max(v1,v2);
}

signed main()
{
    int t;
    cin >> t;
    int z = 1;
    while (t--)
    {
        string s; getline(cin, s);
        int n, w, k;
        cin >> n >> w >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[i] = y;
        }
        sort(a.begin(), a.end());
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] - a[i] <= w)
                {
                    count++;
                }
            }
            c[i] = count;
            // cout<<c[i]<<endl;
        }
        // for (auto x : c)
        // {
        //     cout << x << " ";
        // }
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        int ans = f(0, k, dp, c, n);
        cout<<"Case "<<z<<":"<<" "<<ans<<endl;
        z++;
    }
    return 0;
}