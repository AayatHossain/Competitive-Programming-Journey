#include<bits/stdc++.h>
using namespace std;
const int mx = 2e5;
int n;
vector<int> g[mx+1];
vector<bool> v(mx+1,false);
vector<int> dp(mx+1,0);
vector<int> id(mx+1,0);
map<pair<int,int>,int> m;

void dfs(int u){
    v[u]=true;
    for(auto x: g[u]){
        if(!v[x]){
            int mux = m[{u,x}];
            if(mux >= id[u]){
                dp[x] = dp[u];
                id[x] = mux;
            }else{
                dp[x] = dp[u] + 1;
                id[x] = mux;
            }
            dfs(x);
        }
    }
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        
        for(int i = 0; i < n-1; i++){
            int u,x; cin>>u>>x;
            m[{u,x}] = i;
            m[{x,u}] = i;
            g[u].push_back(x);
            g[x].push_back(u);
        }
        dp[1]=1;
        id[1]=0;
        
        dfs(1);
        int mx = INT_MIN;
        for(int i = 1; i <= n; i++){
            mx = max(mx, dp[i]);
        }
        cout<<mx<<endl;


        fill(v.begin(),v.begin()+n+1,false);
        fill(dp.begin(),dp.begin()+n+1,0);
        fill(id.begin(),id.begin()+n+1,0);
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        m.clear();

        
    }
    return 0;
}