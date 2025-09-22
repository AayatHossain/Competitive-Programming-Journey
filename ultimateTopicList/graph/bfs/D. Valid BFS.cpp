#include<bits/stdc++.h>
using namespace std;
int n;
const int N =2e5+1;
vector<int> g[N];
vector<bool> vis(N,false);
vector<int>before;
vector<int>after;
vector<int>beforeIndx(N+1);

bool cmp(int a, int b){
    return beforeIndx[a] < beforeIndx[b];
}

void bfs(){
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        after.push_back(u);
        for(auto v: g[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
}

signed main(){
    cin>>n;
    for(int i =1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        int x;cin>>x;
        before.push_back(x);
        beforeIndx[before[i-1]] = i;
    }
    for(int i = 1; i <= n; i++){
        sort(g[i].begin(),g[i].end(),cmp);
    }
    bfs();
    if(before==after){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}