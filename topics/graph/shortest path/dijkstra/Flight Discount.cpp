#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 1e5 + 1;
vector<pair<int, int>> g[N];
vector<pair<int, int>> rg[N];
vector<int> d(N, LLONG_MAX / 2);
vector<int> rd(N, LLONG_MAX / 2);
void f(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    if (s == 1)
    {
        q.push({0, 1});
        d[1] = 0;
        while (!q.empty())
        {
            int u = q.top().second;
            int du = q.top().first;
            q.pop();
            if (du != d[u])
                continue;
            for (auto x : g[u])
            {
                int v = x.first;
                int w = x.second;
                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    q.push({d[v], v});
                }
            }
        }
    }
    else
    {
        q.push({0, n});
        rd[n] = 0;
        while (!q.empty())
        {
            int u = q.top().second;
            int du = q.top().first;
            q.pop();
            if (du != rd[u])
                continue;
            for (auto x : rg[u])
            {
                int v = x.first;
                int w = x.second;
                if (rd[u] + w < rd[v])
                {
                    rd[v] = rd[u] + w;
                    q.push({rd[v], v});
                }
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
    }
    f(1);
    f(n);
    int ans = LLONG_MAX/2;
    for(int i = 1; i <= n; i++){
        for(auto x: g[i]){
            int u,v,w; 
            u = i; v = x.first; w = x.second;
            if(d[u]!=LLONG_MAX/2 && rd[v]!=LLONG_MAX/2){
                ans = min(ans, d[u]+rd[v] + w/2);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}