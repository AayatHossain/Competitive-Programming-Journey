#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> g[], int s,int d, int wt){
    g[s].push_back({d,wt});
    g[d].push_back({s,wt});
    // cout<<s<<" "<<d<<" "<<wt<<endl;
}
void dfs(vector<pair<int,int>> g[],vector<bool> &vis, int src, int &p, int temp, int &ans){
    if(temp > ans){
        p = src;
        ans = temp;
    }
    // cout<<src<<endl;

    vis[src] = true;
    for(auto x : g[src]){
        int v = x.first;
        int wt = x.second;
        if(!vis[v]){
            dfs(g, vis, v,p, temp + wt, ans);
        }
    }
}


void dfs2(vector<pair<int,int>> g[],vector<bool> &vis, int src, int temp, vector<int> &dist){
    
    vis[src] = true;
    dist[src] = temp;
    for(auto x : g[src]){
        int v = x.first;
        int wt = x.second;
        if(!vis[v]){
            dfs2(g, vis, v, temp + wt, dist);
        }
    }
}
int main(){
    int t;cin>>t;
    int it = 1;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> g[n];
        for(int i =0 ; i < n - 1; i++){
            int u,v,w;
            cin>>u>>v>>w;
            addEdge(g,u,v,w);
        }
       
        int p, q;
        vector<bool> vis(n, false);
        int ans = 0;
        //find farthest node p from zeroth node
        dfs(g,vis, 0, p, 0, ans);

        //find q from p
        fill(vis.begin(), vis.end(), false);
        ans = 0;
        dfs(g, vis, p, q, 0, ans);
        // cout<<p<<" "<<q<<endl;


        vector<int> pDist(n);
        vector<int> qDist(n);
        fill(vis.begin(), vis.end(), false);
        dfs2(g,vis, p, 0, pDist);

        fill(vis.begin(), vis.end(), false);
        dfs2(g,vis, q, 0, qDist);

        cout<<"Case "<<it<<":"<<endl;
        it++;
        for(int i = 0; i < n; i++){
            cout<<max(pDist[i], qDist[i])<<endl;
        }
    }
    return 0;
}