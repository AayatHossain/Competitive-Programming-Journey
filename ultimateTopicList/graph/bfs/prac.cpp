#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>> &g, vector<bool> &vis, int u, set<int> &s){
        vis[u]=true;
        s.insert(u);
        for(auto v: g[u]){
            if(!vis[v]){
                bool f = dfs(g,vis,v,s);
                if(f){
                    s.erase(u);
                    return true;
                }
            }else if(s.find(v)!=s.end()){
                s.erase(u);
                return true;
            }
        }
        s.erase(u);
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
       vector<vector<int>> g(V);
        vector<bool> vis(V,false);
        set<int> s;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].push_back(v);
        }
        bool f=0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                f = dfs(g,vis,i,s);
            }
            if(f){
                break;
            }
        }
        return f;
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;           // number of vertices
    cin >> m;           // number of edges

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // if your input vertices are 1-based, uncomment next line:
        // u--; v--;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    Solution sol;
    bool hasCycle = sol.isCyclic(n, edges);

    if (hasCycle)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
