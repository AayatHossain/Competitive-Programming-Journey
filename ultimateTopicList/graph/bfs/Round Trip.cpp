#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
vector<int> p(N,-1);

vector<int> s;
void path(int u, int v){
    s.push_back(v);
    while(u!=v){
        s.push_back(u);
        u = p[u];
    }
    s.push_back(v);
}


bool dfs(int u){
    vis[u]=true;
    for(auto v: g[u]){
        if(!vis[v]){
            p[v]=u;
            if(dfs(v)){
                return true;
            }
        }else if(p[u]!=v){
            path(u,v);
            return true;
        }
    }
    return false;
}



signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int f = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){

            // for(int j=1;j<=n;j++){
            //     vis[j]=false;
            //     p[j]=-1;
            // }
            f = dfs(i);
            if(f){
                break;
            }
        }
    }
    if(f){
        cout<<s.size()<<endl;
        for(auto x: s){
            cout<<x<<" ";
        }
        cout<<'\n';
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}