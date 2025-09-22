#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
vector<int> dist(N,-1);
int ans = INT_MAX;

void bfs(int s){
    for(int i=1;i<=n;i++){
        vis[i]=false;
        dist[i]=-1;
    }
    queue<pair<int,int>> q;
    q.push({s,-1});
    vis[s]=true;
    dist[s]=0;
    while(!q.empty()){
        int u = q.front().first;
        int up = q.front().second;
        q.pop();
        for(auto v: g[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                vis[v]=true;
                q.push({v,u});
            }else if(up!=v){
                ans = min(ans, dist[u]+dist[v]+1);
            }
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}