#include<bits/stdc++.h>
using namespace std;
const int N = 100+1;
int n;
vector<pair<int,int>> g[N];
vector<bool> v(N,false);
int ans = INT_MAX;
void dfs(int u, int p, int val){
    if(u==1 && p != -1){
        ans = min(ans, val);
        // cout<<p<<" "<<val<<endl;
        return;
    }
    v[u]=true;
    for(auto q: g[u]){
        int s = u;
        int d = q.first;
        int w = q.second;
        if(v[d] && d==1 && p==1)continue;
        if(!v[d] || d==1){
            
            int c = 0;
            if(w<0){
                c = -w;
            }
            dfs(d,s,val+c);
        }
    }
    v[u]=false;

    return;
}
signed main(){
    cin>>n;
    for(int i =1;i<=n;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }
    dfs(1,-1,0);
    cout<<ans<<endl;
    return 0;
}