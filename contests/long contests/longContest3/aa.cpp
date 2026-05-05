#include<bits/stdc++.h>
using namespace std;
#define N (int)1e5
vector<int> g[N];
vector<int> vis;
vector<int> par;
int cycleStart = -1;
int cycleEnd = -1;

bool dfs(int u, int parU){
    vis[u] = true;
    for(auto v : g[u]){
        if(v==parU){
            continue;
        }else{
            if(vis[v]){
                cycleStart = v;
                cycleEnd = u;
                return true;
            }else{
                par[v] = u;
                if(dfs(v, par[v])){
                    return true;
                }
            }
            
        }
    }
    return false;
}

signed main(){
    int n,m;cin>>n>>m;
    vis.assign(n, false);
    par.assign(n, -1);
    for(int i = 0; i < m; i++){
        int x,y;cin>>x>>y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i] && dfs(i, par[i])){
            break;
        }
    }
    if(cycleStart==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for(int i = cycleEnd; i != cycleStart; i = par[i]){
            cycle.push_back(i);
        }
        cycle.push_back(cycleStart);
        cout<<cycle.size()<<endl;
        for(int i = 0; i < cycle.size(); i++){
            cout<<cycle[i]+1<<" ";
        }
        cycle.push_back(cycleStart);
        cout<<endl;
    }
    return 0;
}