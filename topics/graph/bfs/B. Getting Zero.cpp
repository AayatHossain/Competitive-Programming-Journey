#include<bits/stdc++.h>
using namespace std;
const int N = 32768;
vector<bool> vis(N, false);
vector<int> dist(N,0);
void bfs(){
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        int v1 = (u-1+N)%N;
        int v2 = (u/2)%N;
        int v3 = (u/2 + N/2)%N;
        if(!vis[v1]){
            q.push(v1);
            dist[v1]=dist[u]+1;
            vis[v1]=true;
        }
        if(!vis[v2]){
            q.push(v2);
            vis[v2]=true;
            dist[v2]=dist[u]+1;
        }
        if(!vis[v3]){
            q.push(v3);
            vis[v3]=true;
            dist[v3]=dist[u]+1;
        }
    }
}
int n;
signed main(){
    cin>>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)cin>>a[i];
    bfs();
    for(int i = 0; i <n;i++){
        cout<<dist[a[i]]<<" ";
    }

    return 0;
}