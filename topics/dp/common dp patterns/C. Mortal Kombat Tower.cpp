#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        if(n==1){
            cout<<a[0]<<endl;continue;
        }
        int dp[n][2];
        memset(dp, 0, sizeof dp);
        dp[0][0]=a[0];
        dp[0][1]=INT_MAX/2;
        dp[1][0]= dp[0][0]+a[1];    
        dp[1][1]= dp[0][0];
        for(int i = 2; i < n; i++){
            for(int j = 0; j <= 1; j++){
                int v1 = dp[i-1][!j]+a[i];
                int v2 = dp[i-2][!j]+a[i]+a[i-1];
                if(j==1){
                    v1-=a[i];
                    v2-=(a[i]+a[i-1]);
                }
                dp[i][j]=min(v1,v2);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout<<dp[i][1]<<" ";
        // }
        // cout<<endl;
        cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    }
}