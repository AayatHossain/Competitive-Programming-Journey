#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> g[N+1];
vector<bool> vis(N+1,false);
vector<int> dist(N+1,-1);
vector<int> p(N+1,0);
int n,m,k;

void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1]=true;
    dist[p[1]]=0;
    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int v: g[u]){
            if(!vis[v]){
                dist[p[v]] = max(dist[p[v]], d+1);
                vis[v]=true;
                q.push({v,d+1});
            }
        }
    }
    return;
}

signed main(){
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }

    for(int i = 1; i <= m; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();
    for(int i = 1; i<= k; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return 0;
}