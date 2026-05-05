#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9+7;

signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> dp(n, INT_MAX);
    dp[0]=0;
    for(int i = 0; i < n-1; i++){
        if(i+2 < n){
            dp[i+1] = min(dp[i] + abs(a[i]-a[i+1]), dp[i+1]);
            dp[i+2] = min(dp[i] + abs(a[i]-a[i+2]), dp[i+2]);
        }else{
            dp[i+1] = min(dp[i] + abs(a[i]-a[i+1]), dp[i+1]);
        }
    }
    cout<<dp[n-1]<<endl;

    return 0;
}