#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, x; cin>>n>>x;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++)cin>>a[i];
    for(int i = 1; i <= n; i++)cin>>b[i];
    int dp[n+1][x+1];
    memset(dp, 0, sizeof dp);
    // for(int i = 0; i <=n; i++)dp[i][0]=1;
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 1; j--){
            int v1=0,v2=0;
            v1=dp[i-1][j];
            if(j-a[i] >=0)v2=dp[i-1][j-a[i]]+b[i];
            dp[i][j]=max(v1,v2);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}