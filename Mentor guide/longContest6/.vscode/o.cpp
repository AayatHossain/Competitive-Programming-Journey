#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+1;
const int mod = 1e9+7;
vector<int> g[N];
pair<int,int> dp[N];
int n;
pair<int,int> f(int u, int p){
    int dark = 1, white = 1;
    if(dp[u].first != -1)return dp[u];
    for(auto v: g[u]){
        if(v!=p){
            pair<int,int> temp = f(v,u);
            dark = (dark*(temp.second))%mod;
            white = (white*((temp.first+temp.second)%mod))%mod;
        }
    }
    return dp[u] = {dark,white};
}
signed main(){
    
    cin>>n;

    for(int i = 1; i <= n; i++){
        dp[i] = {-1,-1};
    }
    for(int i =0 ; i < n-1; i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pair<int,int> ans = f(1,-1);
    cout<<(ans.first+ans.second)%mod<<endl;
    return 0;
}