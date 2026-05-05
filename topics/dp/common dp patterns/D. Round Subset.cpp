#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod =  998244353;   
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    
    for(int i =0;i<n;i++)cin>>a[i];
    int s = accumulate(a.begin(),a.end(),0);
    
    vector<int> dp(s+1);

    dp[0]=1;
    for(int i = 0; i < n; i++){
        for(int j = s; j >= 0; j--){
            if(j-a[i] >= 0 && dp[j-a[i]]){
                dp[j] = (dp[j-a[i]]%mod+dp[j]%mod)%mod;
            }
        }
    }
    // for(auto x: dp){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    int ans=0;
    for(int i = 0 ; i<= s; i++){
        ans = (ans%mod + (((i+1)/2)*(dp[i]%mod))%mod);
    }
    // cout<<ans<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i]; j++){
           
            ans = ans%mod + ((a[i] - (a[i]%mod+j%mod+1)%mod/2)*dp[j])%mod;
            // ans -= ((j+1)/2)*dp[j];
            // ans += a[i]*dp[j];
        }
    }
    cout<<ans<<endl;
}