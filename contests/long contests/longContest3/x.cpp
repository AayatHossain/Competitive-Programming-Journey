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
        // cout<<s<<" ";
        q.pop();
        for(auto x: graph[s]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    // cout<<endl;
}

int main(){
    int n, m;cin>>n>>m;
    vector<int> g[n];
    vector<bool> vis(n, false);
    for(int i = 0; i < m ; i++){
        int x,y;cin>>x>>y;
        x--;y--;
        addEdge(g,x,y);
    }
    int count = 0;
    int prev = -1;
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            count++;
            bfs(g,vis,n,i);
            if(prev == -1){
                prev = i+1;
            }else{
                ans.push_back({prev, i+1});
                prev = i+1;
            }
            // cout<<prev<<endl;

        }
    }
    // cout<<count<<endl;
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}