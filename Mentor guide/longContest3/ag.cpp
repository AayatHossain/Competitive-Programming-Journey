#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int u, v, w;
};
signed main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u,v,w;cin>>u>>v>>w;
        edges.push_back({--u,--v,w});
    } 
    vector<int> par(n,-1);
    vector<int> dist(n, LLONG_MAX);
    dist[0] = 0;
    int x = -1;
    for(int i = 0; i < n ; i++){
       
        x = -1;
        for(auto edge: edges){
            if(dist[edge.u] < LLONG_MAX){
                if(dist[edge.v] > dist[edge.u] + edge.w){
                    dist[edge.v] = max(LLONG_MIN, dist[edge.u] + edge.w);
                    par[edge.v] = edge.u;
                    x = edge.v;
                }
            }
        }
        
    }
    if(x == -1){
        cout<<"NO"<<endl;
    }else{
        for(int i = 0; i < n; i++){
            x = par[x];
        }
        vector<int> path;
        int y = x;
        do {
            path.push_back(y);
            y = par[y];
        } while (y != x);
        path.push_back(y);

        reverse(path.begin(), path.end());
        cout<<"YES"<<endl;
        for(auto x: path){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
}