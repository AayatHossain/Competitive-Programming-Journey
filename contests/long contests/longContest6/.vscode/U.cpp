#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 1e5;
int dp[N][10];
int n,m;
int f(int i, int j, string &s, string &t){
    if(j==m){return 1;}
    if(i==n){return 0;}
    if(dp[i][j] != -1){return dp[i][j];}
    if(s[i]==t[j]){
        return dp[i][j] = (f(i+1, j+1, s, t)%mod + f(i+1, j, s, t)%mod)%mod;
    }else{
        return dp[i][j] = f(i+1, j, s, t)%mod;
    }
}
 
 
signed main(){
    string s,t;cin>>s>>t;
     n = s.size();
     m = t.size();
    memset(dp, -1, sizeof dp);
    int ans = f(0,0,s,t);
    cout<<ans<<endl;
        
    return 0;
}