#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int src, int dst){
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}
void bfs( vector<int>g[],vector<bool> &vis,  vector<int> &p,int s){
    queue<int> q;
    // set<int> cycleStart;
    int start = -1;
    int end = -1;
    q.push(s);
    vis[s] = true;
    int found = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int u = q.front();
            q.pop();
            
            for(auto v: g[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                    p[v] = u;
                }else{
                    if(p[u] != v){
                        found = 1;
                        start = v;
                        end = u;
                        break;
                    }
                }
            }
        }
        if(found){
            break;
        }
    }
    cout<<start<<end<<endl;
    // return;
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> route;
        
        route.push_back(start);
        route.push_back(end);
        
        int curr = p[end];
        
        // route.push_back(d);
        while(curr != start){
            
            route.push_back(curr);
            curr = p[curr];
            for(int i = 0; i < route.size(); i++){
                cout<<route[i] <<" ";
            }
            return;
            
        }
        route.push_back(start);
        reverse(route.begin(), route.end());
        cout<<route.size()<<endl;
        for(auto x: route){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
}
signed main(){
    int n,m;cin>>n>>m;
    vector<int>g[n];
    vector<bool> vis(n,false);
    for(int i = 0; i < m; i++){
        int x,y;cin>>x>>y;
        x--;y--;
        addEdge(g,x,y);
    }
    int src = 0;
    vector<int> p(n,-1);
    bfs(g,vis,p,src);
    return 0;
}