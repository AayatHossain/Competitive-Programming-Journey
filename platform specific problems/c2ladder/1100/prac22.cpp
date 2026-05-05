#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> g[N];
vector<int> vis(N,false);
vector<int> p(N,-1);
vector<int> ans;
int n,m;

bool bfs(){
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==n)return true;
        for(auto v: g[u]){
            if(!vis[v]){
                q.push(v);
                p[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}

void makepath(){
    int temp = n;
    while(p[temp] != -1){
        ans.push_back(temp);
        temp = p[temp];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
}



signed main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool f = bfs();
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        makepath();
        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}