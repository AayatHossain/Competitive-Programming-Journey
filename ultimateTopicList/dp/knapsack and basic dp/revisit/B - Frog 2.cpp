#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9+7;

signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> dp(n, INT_MAX);
    dp[0]=0;
    for(int i = 0; i < n-1; i++){
        
        for(int j=1;j<=k && i+j < n;j++){
            dp[i+j]= min(dp[i]+abs(a[i]-a[i+j]), dp[i+j]);
        }
    }
    cout<<dp[n-1]<<endl;

    return 0;
}