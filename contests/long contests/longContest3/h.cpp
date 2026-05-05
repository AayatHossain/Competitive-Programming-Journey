#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> graph[], int src, int dst, int wt){
    graph[src].push_back({dst, wt});
    graph[dst].push_back({src, wt});
}

void dfs(vector<pair<int,int>> graph[],vector<bool> &vis, int n, int src, int &ans, int temp, int &last){
    // cout<<src<<" ";
    vis[src] = true;
    if(temp > ans){
        last = src;
    }
    ans = max(ans, temp);
    for(auto x: graph[src]){
        if(!vis[x.first]){
            dfs(graph, vis, n, x.first, ans, temp+x.second, last);
        }
    }
}

signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> graph[n];
        for(int i = 0; i < n-1; i++){
            int x,y,z;cin>>x>>y>>z;
            addEdge(graph, x,y,z);
        }
        vector<bool> vis(n, false);
        int ans = 0;    //its dummy, real answer is ans1
        int temp = 0;
        int last=-1;
        dfs(graph, vis, n, 0, ans, temp, last);
        int ans1 = 0;
        temp = 0;
        fill(vis.begin(), vis.end(), false);
        dfs(graph, vis, n, last, ans1, temp, last);
        cout<<"Case "<<c<<": "<<ans1<<endl;
        c++;
    }

    return 0;
}