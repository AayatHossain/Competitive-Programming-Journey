#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9 + 7;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int dp[2][k + 1][k + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            for (int l = j; l >= 0; l--)
            {
                int curr = (i&1);
                int prev = !curr;

                int v1=0,v2=0,v3=0;
                v1 = dp[prev][j][l];
                if(j-a[i-1] >=0){
                    v2 = dp[prev][j-a[i-1]][l];
                }
                if(j-a[i-1] >= 0 && l-a[i-1]>=0){
                    v3 = dp[prev][j-a[i-1]][l-a[i-1]];
                }
                dp[curr][j][l]= (v1|v2)|v3;
            }
        }
    }
    vector<int> v;
    for (int i = 0; i <= k; i++)
    {
        if(dp[(n&1)][k][i]){
            v.push_back(i);
        }
    }
    cout<<v.size()<<endl;
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}