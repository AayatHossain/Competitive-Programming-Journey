//important for distinct ordered ways
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
signed main(){
    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<int> dp(s+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= s;j++){
            if(j-a[i] >= 0){
                dp[j] =(dp[j]%mod +  dp[j-a[i]]%mod)%mod;
            }
        }
        
    }
    cout<<dp[s]%mod<<endl;
    return 0;
}