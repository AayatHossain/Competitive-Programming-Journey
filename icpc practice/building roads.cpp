#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> g[N+1];
vector<bool> v(N+1,false);
int n,m;
void dfs(int u){
    v[u]=true;
    for(auto w: g[u]){
        if(!v[w]){
            dfs(w);
        }
    }
}
signed main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c =0;
    vector<pair<int,int>> a;
    for(int i = 1; i<= n; i++){
        if(!v[i]){
            dfs(i);
            c++;
            if(i!=1){
                a.push_back({1,i});
            }
        }
    }
    cout<<c-1<<endl;
    for(auto x: a){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}