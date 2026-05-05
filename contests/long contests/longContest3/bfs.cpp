#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int src, int dst){
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}
void bfs(vector<int> graph[],vector<bool> &vis, int n, int src){
   
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int s = q.front();
        cout<<s<<" ";
        q.pop();
        for(auto x: graph[s]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    cout<<endl;
}
void dfs(vector<int> graph[],vector<bool> &vis, int n, int src){
    cout<<src<<" ";
    vis[src] = true;
    for(auto x: graph[src]){
        if(!vis[x]){
            dfs(graph, vis, n, x);
        }
    }
}
signed main(){
    int n = 8;
    vector<int> graph[n];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);

    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 7);

    vector<bool> vis(n, false);

    bfs(graph, vis, n, 0);
    fill(vis.begin(), vis.end(), false);
    dfs(graph, vis, n, 0);
    cout<<endl;
   
    return 0;
}