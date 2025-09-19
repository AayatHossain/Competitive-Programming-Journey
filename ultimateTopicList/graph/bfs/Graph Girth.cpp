#include <bits/stdc++.h>
using namespace std;
const int N = 2501;
int n, m;
vector<int> g[N];
vector<int> p(N, -1);
vector<int> vis(N, false);
set<pair<int, int>> cycles;

void findCycle(int u, int parent) {
    vis[u] = true;
    p[u] = parent;
    
    for (auto v : g[u]) {
        if (!vis[v]) {
            findCycle(v, u);
        } else if (v != parent) {
            // Cycle detected - store the back edge
            cycles.insert({min(u, v), max(u, v)});
        }
    }
}

// 6 7
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 5 3
// 1 6

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            findCycle(i,-1);
        }
    }

    for(auto x: cycles){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}