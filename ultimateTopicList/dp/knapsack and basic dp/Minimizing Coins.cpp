#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<int> dp(k+1);
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        int ans = 1e7;
        // cout<<ans<<endl;
        for(int j = 0; j < n; j++){
            if(i-a[j] >= 0){
                ans = min(ans, 1+dp[i-a[j]]);
            }
        }
        // if(i==k)cout<<ans<<endl;
        dp[i] = ans;
    }
    // for(auto x: dp)cout<<x<<endl;
    if(dp[k]==1e7)dp[k]=-1;
    cout<<dp[k]<<endl;
    return 0;
}