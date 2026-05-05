#include<bits/stdc++.h>
using namespace std;
const int N = 2501;
int n,m;
vector<int> g[N];
vector<int> dis(N,-1);
int ans = INT_MAX;

void bfs(int s){
    for(int i=1;i<=n;i++){
        dis[i]=-1;
    }

    queue<int> q;
    q.push(s);
    dis[s]=0;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: g[u]){
            if(dis[v]>=dis[u]){
                ans = min(ans, dis[u]+dis[v]+1);
                
            }else if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

signed main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    if(ans == INT_MAX){
        ans = -1;
    }
    cout<<ans<<endl;
    return 0;
}