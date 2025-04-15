#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int src, int dst){
    graph[src].push_back(dst);
}
void dfs(vector<int> g[], vector<bool> &vis, int n, int src,map<int, int> &cM){
    cM[src]++;
    vis[src] = true;
    // cout<<src<<" ";
    for(auto dst: g[src]){
        if(!vis[dst]){
            dfs(g,vis,n,dst,cM);
        }
    }
}
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int k,n,m;cin>>k>>n>>m;
        vector<int> pos(k);
        for(int i = 0; i < k; i++){
            cin>>pos[i];
        }
        vector<int> g[n];
        for(int i = 0; i < m; i++){
            int x,y;cin>>x>>y;
            x--;y--;
            addEdge(g,x,y);
        }
        map<int, int> cM;
        for(int i = 0; i < k; i++){
            vector<bool> vis(n, false);
            dfs(g,vis,n, pos[i]-1, cM);
        }
        int count = 0;
        for(auto x : cM){
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second >= k){
                count++;
            }
        }
        cout<<"Case "<<c<<": "<<count<<endl;
        c++;
    }
    return 0;
}