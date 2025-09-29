#include<bits/stdc++.h>
using namespace std;
const int N = 4001;
vector<int> g[N];
vector<bool> vis(N,false);
int n; string s;
int cnt = 0;

pair<int,int> dfs(int u){
    vis[u]=true;
    pair<int,int> curr = {0,0};
    if(s[u-1]=='B')curr.first++;
    else curr.second++;

    for(int v: g[u]){
        if(!vis[v]){
            pair<int,int> p = dfs(v);
            curr = {curr.first + p.first, curr.second + p.second};
        }
    }

    if(curr.first==curr.second)cnt++;
    return curr;
}

signed main(){
    int t; cin>>t;
    while(t--){
        cin>>n;

        cnt = 0;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            vis[i]=false;
        }

        for(int i = 2; i <= n; i++){
            int x; cin>>x;
            g[x].push_back(i);
        }
        cin>>s;

        pair<int,int> p = dfs(1);
        cout<<cnt<<endl;


    }
    return 0;
}