#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 1;
vector<int> g[N];
vector<bool> vis;
vector<int> t;

bool dfs(int u, int c)
{
    vis[u] = true;
    t[u] = c;
    
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if(!dfs(v,!c)){
                return false;
            }
        }
        else
        {
            if (t[v] == t[u])
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    int q = 1;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        // Resize and initialize vectors for the current test case
        vis.assign(n+1, false);
        t.assign(n+1, -1);
        for (int i=1; i<=n; i++) {
            g[i].clear();
        }
        
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        bool f = true;
        for (int i=1; i<=n; i++) {
            if (!vis[i]) {
                if (!dfs(i, 0)) {
                    f = false;
                    break;
                }
            }
        }
        
        cout << "Scenario #" << q << ":\n";
        if (!f) {
            cout << "Suspicious bugs found!\n";
        } else {
            cout << "No suspicious bugs found!\n";
        }
        q++;
    }
    return 0;
}