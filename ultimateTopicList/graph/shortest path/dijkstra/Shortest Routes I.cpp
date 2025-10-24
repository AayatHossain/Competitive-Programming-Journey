#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+1;
vector<pair<int,int>> g[N];
vector<bool> vis(N,false);
vector<int> d(N,LLONG_MAX/2);
int n,m;
void f(){
    d[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        // cout<<u<<endl;
        for(auto x: g[u]){
            int v = x.first;
            int w = x.second;
            
            if(d[u]+w < d[v]){
                d[v] = d[u] + w;
                pq.push({d[v],v});

            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

}

signed main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    f();
    return 0;
}