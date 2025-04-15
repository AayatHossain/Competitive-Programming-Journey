#include<bits/stdc++.h>
using namespace std;
#define int long long
void addEdge(vector<pair<int,int>> graph[], int src, int dst, int wt){
    graph[src].push_back({dst, wt});
}
void algo(vector<pair<int,int>> g[], vector<bool> &vis, vector<int> &dst, int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    dst[src]= 0;
    while(!pq.empty()){
        
            auto u = pq.top();
            pq.pop();
            if(vis[u.second]){continue;}
            vis[u.second] = true;
            for(auto v: g[u.second]){
                if(u.first + v.second < dst[v.first]){
                    dst[v.first] = u.first + v.second;
                    pq.push({dst[v.first], v.first});
                }
            }
        
    }
}
signed main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>> g[n];
    vector<bool> vis(n, false);
    for(int i = 0; i < m; i++){
        int x,y,z; cin>>x>>y>>z;x--;y--; z;
        addEdge(g,x,y,z);
    }
    vector<int> dst(n,LLONG_MAX);
    algo(g,vis,dst,0);
    for(int i = 0; i < n; i++){
        cout<<dst[i]<<" ";
    }
    cout<<endl;
    return 0;
}