#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int n, c; cin>>n>>c;
    vector<int> v(n+1);
    vector<int> w(n+1);
    for(int i = 1; i <= n; i++){cin>>w[i];cin>>v[i];}
   
    vector<vector<int>> dp(n+1,vector<int>(c+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = c; j >= 1; j--){
            int v1,v2=0;
            v1 = dp[i-1][j];
            if(j-w[i] >= 0){v2=v[i]+dp[i-1][j-w[i]];}
            dp[i][j] = max(v1,v2);
        }
    }
    cout<<dp[n][c]<<endl;
}