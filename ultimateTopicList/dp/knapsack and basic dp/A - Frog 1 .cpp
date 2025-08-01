#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<int> dp(n);
    // dp[n] = INT_MIN;
    for(int i = n-2; i >= 0; i--){
   
        int v1 = INT_MAX, v2 = INT_MAX;
        if(i+1 < n)v1=abs(a[i+1]-a[i])+dp[i+1];
        if(i+2 < n)v2=abs(a[i+2]-a[i])+dp[i+2];
        dp[i] = min(v1, v2);
        // cout<<v1<<" "<<v2<<endl;
    }
    // for(auto x: dp)cout<<x<<endl;
    cout<<dp[0]<<endl;
    return 0;
}