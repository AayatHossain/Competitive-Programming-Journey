#include<bits/stdc++.h>
using namespace std;
#define int long long
int n; string s;
int dp[100][100];
int f(int b, int e){
    if(b >= e)return 0;
    if(dp[b][e] != -1)return dp[b][e];
    if(s[b] != s[e]){
        int v1 = 1+f(b,e-1);
        int v2 = 1+f(b+1,e);
        return dp[b][e] = min(v1,v2);
    }else{
        return dp[b][e] = f(b+1,e-1);
    }
}
signed main(){
    int t;cin>>t; int c = 1;
    while(t--){
        memset(dp, -1 , sizeof dp);
        cin>>s;
        n = s.size();
        
        cout<<"Case "<<c<<": "<<f(0,n-1)<<endl;
        c++;
    }
    return 0;
}