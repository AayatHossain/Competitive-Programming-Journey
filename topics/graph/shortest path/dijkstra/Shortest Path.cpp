#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
vector<int> p(N, -1);
vector<int> d(N, LLONG_MAX / 2);
vector<pair<int, int>> res;
int n, m, s, t;

int f()
{
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (auto x : g[u])
        {
            int v = x.first;
            int w = x.second;

            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                p[v] = u;
            }
        }
    }
    return d[t];
}

void path(int v)
{
    while (p[v] != -1)
    {
        res.push_back({p[v], v});
        v = p[v];
    }
}

signed main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int c = f();
    path(t);

    if (c!=LLONG_MAX/2)
    {
        cout << c << " " << res.size() << endl;
        for (int i = res.size()-1; i >=0 ; i--)
        {
            cout << res[i].first << " " << res[i].second << endl;
        }
    }else{
        cout<<-1<<endl;
    }

    return 0;
}