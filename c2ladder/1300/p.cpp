#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        int dp[n+1][2];
        
        dp[0][0]=0;
        dp[0][1]=0;
        for(int i = 1; i <= n; i++){
            int mx = dp[i-1][0];
            int mn = dp[i-1][1];
            // if(k1==LLONG_MIN/2){
            //     k1 = 0;
            // }
            // if(k2==LLONG_MIN/2){
            //     k2 = 0;
            // }

            dp[i][0] = max(mx - a[i-1], b[i-1] - mn);
            dp[i][1] = min(mn - a[i-1], b[i-1] - mx);
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        
        cout<<max(dp[n][1],dp[n][0])<<endl;
    }
    return 0;
}