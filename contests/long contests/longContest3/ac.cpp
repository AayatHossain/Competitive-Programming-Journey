#include <bits/stdc++.h>
using namespace std;
#define int long long
// class Pos{   works the same way
//     public:
//     int node; int isUsed; int cost;
// };
struct Pos
{
    int node;
    int isUsed;
    int cost;
};
auto cmp = [](const Pos &a, const Pos &b)
{
    return a.cost > b.cost;
};
vector<vector<pair<int, int>>> g;
vector<vector<int>> dist;
priority_queue<Pos, vector<Pos>, decltype(cmp)> q(cmp);
int n, m;
int dijkstra()
{
    q.push({1, 0, 0});
    dist[1][0] = 0;
    while (!q.empty())
    {
        Pos p = q.top();
        q.pop();
        int u = p.node;
        int used = p.isUsed;
        int c = p.cost;
       
        if (c != dist[u][used])
        {
            continue;
        }

        for (auto x : g[u])
        {
            int v = x.first;
            int wt = x.second;
            if(!used){
                if (c + wt/2 < dist[v][1])
                {
                    dist[v][1] = c + wt / 2;
                    q.push({v, 1, dist[v][1]});
                }
            }

            if (c + wt < dist[v][used])
            {
                dist[v][used] = c + wt;
                q.push({v, used, dist[v][used]});
            }
        }
    }
    return dist[n][1];
}
signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1, vector<int>(2, LLONG_MAX));
    for (int i = 1; i <= m; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        g[s].push_back({d, w});
    }
    cout << dijkstra() << endl;
    return 0;
}