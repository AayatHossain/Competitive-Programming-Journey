#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
signed main(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++)cin>>a[i];
    vector<vector<int>> dp(n, vector<int>(101,0));
    if(a[0]!=0){
        dp[0][a[0]]=1;
    }else{
        for(int i = 1; i <= m; i++){
            dp[0][i]=1;
        }
    }
    for(int i = 1; i < n; i++){
        if(a[i] != 0){
            dp[i][a[i]]= (((dp[i-1][a[i]]%mod+dp[i-1][a[i]-1]%mod)%mod)+dp[i-1][a[i]+1])%mod;
        }else{
            for(int j = 1; j <= m; j++){
                dp[i][j] = (((dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod)+dp[i-1][j+1])%mod;
            }
        }
    }
    int ans = 0;
    if(a[n-1]==0){
        for(int i = 1; i <= m; i++){
            ans = (ans%mod + dp[n-1][i]%mod)%mod;
        }
    }else{
        ans = dp[n-1][a[n-1]]%mod;
    }
    cout<<ans%mod<<endl;
    
 
    return 0;
}
