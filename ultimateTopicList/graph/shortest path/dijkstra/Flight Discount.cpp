#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+1;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
vector<int> p(N, -1);
vector<int> d(N, LLONG_MAX / 2);
int n, m;
int c;
int f()
{
    d[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push({0,1});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();

        if(vis[u])continue;
        vis[u]=true;

        for(auto x: g[u]){
            int v= x.first;
            int w = x.second;

            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push({d[v],v});
                p[v] = u;
            }
        }

    }
    return d[n];
}

void path(int v){
    
    // res.push_back(v);
    int mx = LLONG_MIN;
    while(p[v]!=-1){

        for(auto x: g[p[v]]){
            if(x.first==v){
                mx = max(mx,x.second);
            }
        }

        v = p[v];


    }

    c -= mx/2;
    
}


signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    c = f();
    path(n);
    cout<<c<<endl;

    return 0;
}