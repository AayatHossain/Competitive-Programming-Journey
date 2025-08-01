#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> dp(n);
    dp[n-1] = 0;
    // dp[n] = INT_MIN;
    for(int i = n-2; i >= 0; i--){
        int ans = INT_MAX;
        for(int j = 1; j <= k;j++){
            if(i+j < n){
                ans = min(ans, abs(a[i+j]-a[i])+dp[i+j]);
            }
        }
        dp[i] = ans;
    }
    // for(auto x: dp)cout<<x<<endl;
    cout<<dp[0]<<endl;
    return 0;
}