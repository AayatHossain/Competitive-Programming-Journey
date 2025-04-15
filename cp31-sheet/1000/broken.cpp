#include <bits/stdc++.h>
using namespace std;
int n, m;
// vector<vector<int>> adj;
vector<int> adj[200];
vector<bool> visited;
vector<int> ans;

void dfs(int v){
    visited[v] = true;
    for(int u: adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(){
    visited.assign(n, false);
    ans.clear();
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    // reverse(ans.begin(), ans.end());
}

int main()
{
    cin>>n>>m;
    
    for(int i = 0; i < m; i++){
        int u; cin>>u;
        int count; cin>>count;
        for(int j = 0; j < count; j++){
            int y; cin>>y;
            adj[u-1].push_back(y-1);
        }
    }
    topological_sort();
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    

    
    
    return 0;
}