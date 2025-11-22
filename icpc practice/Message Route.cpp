#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> p(N, -1);
vector<int> ans;
int n, m;

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == n)
            return;

        for (auto v : g[u])
        {
            if (!vis[v])
            {
                p[v] = u;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void path()
{
    if (p[n] == -1)
        return;
    int v = n;
    while (p[v] != -1)
    {
        ans.push_back(v);
        v = p[v];
    }
    ans.push_back(v);
    reverse(ans.begin(),ans.end());
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    path();
    if(ans.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}