#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int f(int i,int prod, vector<int> &a,vector<vector<int>> &dp){
    if(i==a.size()){
        if(prod%2520==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[i][prod]!=-1)return dp[i][prod];
    int v1 = f(i+1, (prod*a[i])%2520,a,dp)%mod;
    int v2 = f(i+1, prod%2520,a,dp)%mod;
    return dp[i][prod]=(v1 + v2)%mod;
}
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    int p = 1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i] %= 2520;
    }
    vector<vector<int>> dp(n,vector<int>(2521,-1));
    int ans = f(0,1,a,dp);
    cout<<ans%mod<<endl;
    return 0;
}