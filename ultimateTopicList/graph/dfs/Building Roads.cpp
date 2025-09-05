#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N];
vector<bool> vis(N,false);

void dfs(int u){
    vis[u] = true;
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

signed main(){
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   
    vector<int> nodes;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            nodes.push_back(i);
        
            dfs(i);
        }
    }
    cout<<nodes.size()-1<<endl;
    for(auto v: nodes){
        if(v+1==1)continue;
        cout<<1<<" "<<v+1<<endl;
    }

}