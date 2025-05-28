#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
vector<int> g[N];
vector<int> dp(N, -1);

int dfs(int u){
    if(g[u].empty()){
        return 0;
    }
    if(dp[u] != -1){
        return dp[u];
    }
    int ms = LLONG_MIN;
    for(auto v : g[u]){
        int val = dfs(v);
        ms = max(ms, val);
    }
    return dp[u] = ms+1;
}

signed main(){
    int n,m; cin>>n>>m;
    for(int i = 0;i < m; i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
    }
    int ans = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i));
    }
    cout<<ans<<endl;
}