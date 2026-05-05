#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int src, int dst){
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}

void bfs(vector<int> g[], int s, int d, int &dtime, int n){
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    int time = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int u = q.front();
            q.pop();
            if(u==d){
                dtime = time;
                return;
            }
            
            for(auto v: g[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        time++;
    }
}

signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> graph[n];
        for(int i = 0; i < m; i++){
            int x,y;
            cin>>x>>y;
            addEdge(graph, x,y);
        }
        int s,d;cin>>s>>d;
        
        int ans = -1;
        for(int i = 0; i < n; i++){
            int time1 = 0, time2 = 0;
            bfs(graph,s,i,time1, n);
            bfs(graph,d,i,time2, n);
            ans = max(ans, time1 + time2);
        }
        cout<<"Case "<<c<<": "<<ans<<endl;
        c++;
    }
    return 0;
}