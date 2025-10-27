#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,t;
const int N = 1e5+1;
int e[N][3];
vector<pair<int,int>> g[N];
vector<pair<int,int>> rg[N];
vector<int> d(N,LLONG_MAX/2);
vector<int> rd(N,LLONG_MAX/2);

void f(int src){
    if(src==s){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> vis(n+1,false);
        q.push({0,src});
        d[src] = 0;
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(auto x: g[u]){
                int v = x.first;
                int w = x.second;
                if(d[u]+w < d[v]){
                    d[v] = d[u]+w;
                    q.push({d[v],v});
                }
            }
        }

    }else{
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> vis(n+1,false);
        q.push({0,src});
        rd[src] = 0;
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(auto x: rg[u]){
                int v = x.first;
                int w = x.second;
                if(rd[u]+w < rd[v]){
                    rd[v] = rd[u]+w;
                    q.push({rd[v],v});
                }
            }
        }
    }
}

signed main(){
    cin>>n>>m>>s>>t;
    for(int i = 0; i < m; i++){
        int u,v,w; cin>>u>>v>>w;
        e[i+1][0] = u;
        e[i+1][1] = v;
        e[i+1][2] = w;
        g[u].push_back({v,w});
        rg[v].push_back({u,w});
    }
    f(s);
    f(t);

    // for(int i = 1; i <= n; i++){
    //     cout<<rd[i]<<" ";
    // }


    int sd = d[t];
    sd--;
    for(int i = 1; i <= n; i++){
        int u = e[i][0];
        int v = e[i][1];
        int w = e[i][2];

        int d1 = d[u];
        int d2 = rd[v];

        int left = sd - (d1+d2);
        int cost = w - left;
        // if(cost==0){
        //     cout<<"YES"<<endl;
        // }else if(cost > 0){
        //     cout<<"Can "<<cost+1<<endl;
        // }else{
        //     cout<<"No"<<endl;
        // }
        if(i==3){
            cout<<d1<<" "<<d2<<" ";
        }
    }

    return 0;
}