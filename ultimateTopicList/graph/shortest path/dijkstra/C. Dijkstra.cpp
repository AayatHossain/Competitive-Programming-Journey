#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+1;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
vector<int> p(N, -1);
vector<int> d(N, LLONG_MAX / 2);
int n, m;

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
    if(d[n]!=LLONG_MAX/2)return 1;
    else return 0;
}

void path(int v){
    vector<int> res;
    res.push_back(v);
    while(p[v]!=-1){
        res.push_back(p[v]);
        v = p[v];
    }
    for(int i = res.size()-1; i >= 0; i--){
        cout<<res[i]<<" ";
    }
    cout<<endl;
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
    int c = f();

    if (c==1)
    {
        path(n);
    }else{
        cout<<-1<<endl;
    }

    return 0;
}