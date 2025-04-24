#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = LLONG_MAX/2;
const int N = 2501, M = 5001;
vector<int> graph[N], graphReversed[N];
bool vis[N], visReversed[N];
struct edge{
    int u, v, w;
};
vector<edge> edges;
vector<int> dist(N, INF);

void dfs(int u){
    vis[u] = true;
    for(int v: graph[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void dfsReversed(int u){
    visReversed[u] = true;
    for(int v: graphReversed[u]){
        if(!visReversed[v]){
            dfsReversed(v);
        }
    }
}

signed main(){
    int n,m;cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back(v);
        graphReversed[v].push_back(u);
        edges.push_back({u, v, -w});
    }
    dfs(1); dfsReversed(n);
    bool change = true;
    dist[1] = 0;
    for(int i = 1; i <= n && change; i++){
        change = false;
        for(auto edge: edges){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                change = true;
                if(i==n && vis[v] && visReversed[v]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<< -dist[n]<<endl;
    return 0;
}