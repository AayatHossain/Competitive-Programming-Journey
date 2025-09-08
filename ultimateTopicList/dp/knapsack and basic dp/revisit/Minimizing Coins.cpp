#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9+7;

signed main(){
    int n,x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> dp(x+1, INT_MAX/2);
    dp[0]=0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i-a[j] >= 0){
                dp[i] = min(1+dp[i-a[j]],dp[i]);
            }
        }
    }
    if(dp[x]==INT_MAX/2){
        dp[x]=-1;
    }
    cout<<dp[x]<<endl;
   

    return 0;
}