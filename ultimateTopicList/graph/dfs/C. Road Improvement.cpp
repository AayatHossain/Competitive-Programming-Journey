#include<bits/stdc++.h>
using namespace std;
int n;
const int N =2e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
map<pair<int,int>,int> m;
map<pair<int,int>,int> ec;
vector<int> freq(N,0);
int k = 0;
vector<int> ans[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        vector<bool> used(k+1,false);
        for(int v: g[u]){
            pair<int,int> p1 = {u,v};
            if(vis[v]){
                used[ec[p1]]=true;
            }
        }
        int canuse =1 ;
        for(int v: g[u]){
            pair<int,int> p1 = {u,v};
            pair<int,int> p2 = {v,u};
            if(!vis[v]){

                while(canuse<=k && used[canuse]){
                    canuse++;
                }

                ec[p1]=canuse;
                ec[p2]=canuse;
                ans[canuse].push_back(m[p1]);
                vis[v]=true;
                q.push(v);
                canuse++;
            }
        }
    }
    

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
        m[{u,v}]=i;
        m[{v,u}]=i;

        freq[u]++;
        freq[v]++;
        k = max(k,freq[u]);
        k = max(k,freq[v]);
    }
    // cout<<k<<endl;
    // for(auto x: m){
    //     cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    // }
    bfs(1);
    cout<<k<<endl;
    for(int i = 1; i <= k;i++){
        cout<<ans[i].size()<<" ";
        for(auto x: ans[i]){
            cout<<x<<" ";
        }
        cout<<'\n';
    }


}