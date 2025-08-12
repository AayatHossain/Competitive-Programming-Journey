#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5+1;
#define int long long
vector<int> a(N);
int f(int i, int t, vector<vector<int>> &dp){
    if(i==n)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    int v1 = INT_MAX, v2 = INT_MAX;
    if(!t){
        v1 = f(i+1, !t,dp);
        if(i+1<n){
          v2 = f(i+2, !t,dp);
        }
        return dp[i][t] = min(v1,v2);
    }else{
        int e1=0,e2=0;
        if(a[i]==1)e1=1;
        if(a[i]==1 && i+1<n && a[i+1]==1){
            e1=1;e2=1;
        }
        if(i+1<n && a[i+1]==1)e2=1;
        v1 = e1+f(i+1,!t,dp);
        if(i+1<n){
            v2=e1+e2+f(i+2,!t,dp);
        }
        return dp[i][t] = min(v1,v2);
   }
}
signed main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = f(0,1,dp);
        cout<<ans<<endl;
    }
    return 0;
}