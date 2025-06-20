#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;



signed main(){
    string s,t;cin>>s>>t;
    int n = s.size();
        int m = t.size();
        int dp[m+1][n+1] = {};
        for(int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j];
                if (t[i] == s[j]) {
                    dp[i + 1][j + 1] += dp[i][j];
                }
                dp[i+1][j+1] = dp[i+1][j+1]%mod;
            }
        }
        cout<<dp[m][n]%mod<<endl;
    return 0;
}