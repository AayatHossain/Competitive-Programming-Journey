#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], vector<bool> &vis, int src, int &edges){
    vis[src] = true;
    for(int dst : g[src]){
        if(!vis[dst]){
            edges++;
            dfs(g,vis,dst,edges);
        }
    }
}
int main(){
    int t;cin>>t;
    int it = 1;
    while(t--){
        int n;cin>>n;
        vector<int> g[n + 1];
        for(int i = 0; i < n-1; i++){
            int s,d;cin>>s>>d;
            g[s].push_back(d);
            g[d].push_back(s);
        }
        vector<bool> vis(n+1, false);
        int edges = 0;
        dfs(g, vis,1, edges);
        int notFriendPairs = ((n*(n-1))/2) - edges;
        cout<<"Case "<<it<<": "<<edges<<" "<<notFriendPairs<<endl;
        it++;
    }
}