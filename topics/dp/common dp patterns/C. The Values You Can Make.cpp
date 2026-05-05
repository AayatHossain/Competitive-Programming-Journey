#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    int dp[2][k+1][k+1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0]=1;
    for(int i = 1; i <= n; i++){
        int curr = i%2;
        int prev = !curr;
        for(int j = k; j >= 0; j--){
        
            for(int l = j; l >= 0; l--){
                int v1 = 0, v2 = 0,v3=0;
                if(j-a[i] >=0 && l - a[i] >= 0){
                    v1 = dp[prev][j-a[i]][l-a[i]];
                }
                if(j-a[i] >=0){
                    v2 = dp[prev][j-a[i]][l];
                }
                v3 = dp[prev][j][l];
                dp[curr][j][l]=(v1|v2)|v3;
            }
        }
    }
    vector<int> ans;
    for(int i  =0 ; i <= k; i++){
        if(dp[n%2][k][i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}