#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main(){
    int n; cin>>n;
    int s = (n*(n+1))/2;
    if(s&1){cout<<0<<endl; return 0;}
    s/=2;
    vector<vector<int>> dp(n+1, vector<int>(s+1,0));
    for(int i = 0; i <= n; i++)dp[i][0]=1;
    for(int i = 1; i <= n;i++){
        for(int j = s; j >= 1; j--){
            int v1 = dp[i-1][j];
            int v2=0;
            if(j-i>=0){
                v2 = dp[i-1][j-i];
            }
            dp[i][j] = (v1+v2)%mod;
        }
    }
    int ans = (dp[n][s]%2==0)?((dp[n][s]/2)%mod):(((dp[n][s]+mod)/2)%mod);
    cout<<ans<<'\n';
    return 0;
}
