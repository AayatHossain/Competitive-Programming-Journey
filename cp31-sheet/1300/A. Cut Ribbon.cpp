#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,a,b,c;cin>>n>>a>>b>>c;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    // for(auto x: dp){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    for(int i = 1; i <= n; i++){
        int mx = -1;
        if(i-a >= 0 && dp[i-a] >= 0){
            mx = max(dp[i-a]+1, mx);
        }
        if(i-b >= 0 && dp[i-b] >= 0){
            mx = max(dp[i-b]+1, mx);
        }
        if(i-c >= 0 && dp[i-c] >= 0){
            mx = max(dp[i-c]+1, mx);
        }
        if(mx!=-1){
            dp[i]=mx;
        }
    }
    // for(auto x: dp){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    cout<<dp[n]<<endl;
    return 0;
}