#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
const int N = 61;
int dp[N][N];
int f(int b, int e){
    if(b==e) return 1;
    if(b > e) return 0;
    if(dp[b][e] != -1) return dp[b][e];
    if(s[b] != s[e]){
        int v1 = f(b+1, e);
        int v2 = f(b, e-1);
        int v3 = f(b+1, e-1);
        return dp[b][e] = v1 + v2 - v3;
    }else{
        int v1 = f(b+1, e);
        int v2 = f(b, e-1);
        return dp[b][e] = 1 + v1 + v2;
    }
}
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin>>s;
        n = s.size();
        cout<<"Case "<<c<<": "<<f(0,n-1)<<endl;
        c++;
    }
    return 0;
}