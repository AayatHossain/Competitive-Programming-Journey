#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, x;
const int N = 2e5+1;
vector<int> g[N];
vector<bool> v(N,false);
vector<int> da(N,0);
vector<int> db(N,0);

void dfs(int u, int c){
    v[u]=true;
    da[u]=c;
    // cout<<u<<" "<<c<<endl;
    for(auto w: g[u]){
        if(!v[w]){
            dfs(w, c+1);
        }
    }
}
void dfs2(int u, int c){
    v[u]=true;
    db[u]=c;
    for(auto w: g[u]){
        if(!v[w] && c+1 < da[w]){
            dfs2(w, c+1);
        }
    }
}

signed main(){
    cin>>n>>x;
    for(int i = 1; i < n; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    for(int i=1;i<=n;i++)v[i]=false;
    dfs2(x,0);

    int maxNode = -1;
    int mx = -1;
    for(int i = 1; i <= n; i++){
        if(db[i] > mx){
            maxNode = i;
            mx = db[i];
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout<<da[i]<<" "<<db[i]<<endl;
    // }
    
    int ans = INT_MIN;
    for(int i= 1; i <= n; i++){
        if(db[i] < da[i] && db[i]!=0){
            ans = max(da[i]*2,ans);
        }
    }
    if(mx==0){
        ans = da[x]*2;
    }
    // cout<<maxNode<<endl;
    cout<<ans<<endl;

    return 0;
}