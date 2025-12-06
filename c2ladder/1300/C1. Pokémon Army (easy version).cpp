#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int dp[n+1][2];
        dp[0][0]=0;
        dp[0][1]=0;
        for(int i = 1; i<=n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+a[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-a[i-1]);
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
    return 0;
}