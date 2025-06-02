#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> dp(N, -1);
vector<int> dp2(N, -1);
set<int> s;
vector<int> g[N];

int dfs(int u, int n){
    int exists = 0;
    if(s.find(u) != s.end()){
        exists = 1;
    }
    if(u==n && exists){
        return 1;
    }
    if(u==n && !exists){
        return 0;
    }
    if(dp[u] != -1)return dp[u];
    int val = LLONG_MIN/2;
    for(int v: g[u]){
        val = max(val, dfs(v,n));
    }
    if(exists){
        return dp[u] = val + 1;
    }else{
        return dp[u] = val;
    }

}

int dfs2(int u, int n){
    int exists = 0;
    if(s.find(u) != s.end()){
        exists = 1;
    }
    if(u==n && exists){
        return 1;
    }
    if(u==n && !exists){
        return 0;
    }
    if(dp2[u] != -1)return dp2[u];
    int val = LLONG_MAX/2;
    for(int v: g[u]){
        val = min(val, dfs2(v,n));
    }
    if(exists){
        return dp2[u] = val + 1;
    }else{
        return dp2[u] = val;
    }

}

signed main(){
    int n,c,m; cin>>n>>c>>m;
    for(int i = 0; i < c; i++){
        int x;  cin>>x;
        s.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x, y; cin>>x>>y;
        g[x].push_back(y);
    }

    int v = dfs(1, n);
    int v2 = dfs2(1, n);
    cout<<v2<<" "<<v<<endl;

    return 0;
}