#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+1;
vector<int> g[N];
vector<bool> v(N, false);
vector<int> res(N);

int dfs(int u){
    v[u]=true;
    int c = 0;
    for(auto w: g[u]){
        if(!v[w]){
            c+= dfs(w);
        }
    }
    res[u]=c;
    return c+1;
}

signed main(){
    int n; cin>>n;
    for(int i = 2; i <= n; i++){
        int x; cin>>x;
        g[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            dfs(i);
        }
    }
    res[1]=n-1;
    for(int i = 1; i <= n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}