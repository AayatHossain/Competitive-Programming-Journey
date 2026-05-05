#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int n ; cin>>n;
    vector<int> dp(n+1,LLONG_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int x = i;
        while(x>0){
            int d = x%10;
            if(d!=0){
                dp[i]=min(dp[i], dp[i-d]+1);
            }
            x/=10;
        }
    }
    // for(auto x: dp)cout<<x<<endl;
    cout<<dp[n]<<endl;
    return 0;
}