#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
signed main(){
    int n; cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j >= 0){
                // dp[i] += dp[i-j]%mod;
                dp[i] = dp[i]%mod + dp[i-j]%mod;
            }
        }
    }
    cout<<dp[n]%mod<<endl;
}