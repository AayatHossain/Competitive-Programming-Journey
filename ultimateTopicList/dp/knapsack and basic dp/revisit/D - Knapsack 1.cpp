#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

signed main(){
    int n,W; cin>>n>>W;
    vector<int> v(n);
    vector<int> w(n);
    for(int i =0;i<n;i++){
        cin>>w[i];
        cin>>v[i];
    }
    int dp[n+1][W+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= 1; j--){
            int v1 =dp[i-1][j];
            int v2 =0;
            if(j-w[i-1] >= 0){
                v2 = dp[i-1][j-w[i-1]] + v[i-1];
            }
            dp[i][j]=max(v1,v2);
        }
    }
    cout<<dp[n][W]<<endl;

    return 0;
}