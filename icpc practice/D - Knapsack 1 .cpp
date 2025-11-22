#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,W; cin>>n>>W;
    vector<int> v(n+1);
    vector<int> w(n+1);
    for(int i = 1; i <= n; i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(W+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= 0; j--){
            int v1 = dp[i-1][j];
            int v2 = 0;
            if(j-w[i] >= 0){
                v2 = dp[i-1][j-w[i]] + v[i];
            }
            dp[i][j] = max(v1,v2);
        }
    }
    cout<<dp[n][W]<<endl;
    return 0;
}