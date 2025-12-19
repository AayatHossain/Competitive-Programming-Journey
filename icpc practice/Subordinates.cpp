#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
vector<int> s(N,0);
int n;
int dfs(int u){
    vis[u]=true;
    int c = 0;
    for(int v: g[u]){
        if(!vis[v]){
            c+=dfs(v);
        }
    }
    s[u]=c;
    return c+1;
}
signed main(){
    cin>>n;
    for(int i = 2; i<= n; i++){
        int v; cin>>v;
        g[v].push_back(i);
    }
 
    int x = dfs(1);
    
    // s[1]=n-1;
    for(int i = 1; i <= n; i++){
        cout<<s[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}