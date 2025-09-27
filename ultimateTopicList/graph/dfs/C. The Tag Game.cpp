#include<bits/stdc++.h>
using namespace std;
int n, x;
const int N = 2e5+1;
vector<int> g[N];
vector<int> vis(N,false);
vector<int> db(N,-1);
vector<int> da(N,-1);

void dfs(int u, int t, int c){
    vis[u]=true;
    if(t==1){
        da[u]=c;
    }else{
        db[u]=c;
    }
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v,t,c+1);
        }
    }
}

signed main(){
    cin>>n>>x;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1,0);
    for(int i= 1; i <= n; i++){
        vis[i]=false;
    }
    dfs(x,2,0);
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(db[i]<da[i]){
            ans = max(ans, da[i]*2);
        }
    }
    cout<<ans<<endl;
    return 0;
}