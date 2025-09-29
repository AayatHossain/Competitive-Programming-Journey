#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =   1e5+1;
vector<bool> vis(N,false);
vector<int> g[N];
int c1=0,c2=0;
int n;

void dfs(int u, int c){
    c==1? c1++ : c2++;
    vis[u]=true;
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v, c==1? 2: 1);
        }
    }
}

signed main(){
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    cout<<c1*c2 - (n-1)<<endl;
    return 0;
}