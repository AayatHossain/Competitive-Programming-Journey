#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 1;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> p(N, -1);
vector<int> ans;

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
                vis[v] = true;
                p[v] = u;
                q.push(v);
                // cout<<v<<endl;
            }
        }
    }
}
void path(){
    int v = n;
    while(p[v] != -1){
        ans.push_back(v);
        v = p[v];
    }
    ans.push_back(1);
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
    if (p[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        path();
        cout<<ans.size()<<endl;
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}