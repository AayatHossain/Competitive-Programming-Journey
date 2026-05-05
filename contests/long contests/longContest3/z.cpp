#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int src, int dst)
{
    graph[src].push_back(dst);
    graph[dst].push_back(src);
}

int bfs(vector<int> g[], vector<bool> &vis, vector<int> &teams, int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    teams[src] = 1;
    int possible = 1;
    while(!q.empty() && possible){
        int s = q.size();
        for(int i = 0; i < s && possible; i++){
            int u = q.front();
            q.pop();
            for(auto v: g[u]){
                if(!vis[v]){
                    if(teams[u]==1){
                        teams[v] = 2;
                    }else{
                        teams[v] = 1;
                    }
                    vis[v] = true;
                    q.push(v);
                }else{
                    if(teams[u]==teams[v] && teams[u] != -1){
                        possible = 0;
                        break;
                    }
                }
            }
            

        }
        
    } 
    if(!possible){
        return 0;
    }else{
        return 1;
    }
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    vector<bool> vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        addEdge(g, x, y);
    }
    vector<int> teams(n, -1);
    int possible = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            possible = bfs(g, vis, teams, i);
            if(possible == 0){
                break;
            }
        }
    }
    
    if(!possible){
        cout<<"IMPOSSIBLE";
    }else{
        for(int i = 0; i < teams.size(); i++){
            cout<<teams[i]<<" ";
        }
    }
    
    cout<<endl;
    return 0;
}