#include<bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
void dfs(vector<pair<int,int>> g[], vector<int> &v, int u,int p, int c){
    if(g[u].size()==1 && p != -1){
        ans = max(ans, c);
        return;
    }
    v[u]=true;
    for(auto u1: g[u]){
        if(!v[u1.first]){
            dfs(g,v,u1.first,u,c+u1.second);
        }
    }
}
signed main(){
    int n; cin>>n;
    vector<pair<int,int>> g[n];
    vector<int> v(n,false);
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(g,v,0,-1,0);
    cout<<ans<<endl;
    return 0;
}