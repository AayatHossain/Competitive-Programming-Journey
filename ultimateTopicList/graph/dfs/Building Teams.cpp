#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,m;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> t(N,-1);
bool dfs(int u, int c)
{
    vis[u] = true;
    t[u] = c;
    
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if(!dfs(v,!c)){
                return false;
            }
        }
        else
        {
            if (t[v] == t[u])
            {
                return false;
            }
        }
    }
    return true;
}
signed main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool f = 1;
    for(int i =1; i<= n; i++){
        if(!vis[i]){
            f = dfs(i,0);
            if(!f){
                break;  
            }
        }
    }
    if(!f){
        cout<<"IMPOSSIBLE"<<'\n';
    }else{
        for(int i = 1; i<= n; i++){
            cout<<t[i]+1<<" ";
        }
    }
    return 0;
}