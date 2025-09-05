#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
vector<int> p(N,-1);

int bfs(int s, int d){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==d)return 1;
        for(auto v: g[u]){
            if(!vis[v]){
                q.push(v);
                p[v]=u;
                vis[v]=true;
                
            }
        }
    }
    return 0;
}
void path(int n){
    vector<int> a;
    while(n != -1){
        a.push_back(n);
        n=p[n];
    }
    cout<<a.size()<<endl;;
    for(int i = a.size()-1; i >= 0; i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

signed main(){
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int f = bfs(1,n);
    if(f){
        path(n);
    }else{
        cout<<"IMPOSSIBLE"<<'\n';
    }
    return 0;
}