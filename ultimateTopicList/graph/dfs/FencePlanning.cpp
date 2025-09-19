#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> g[N];
vector<bool> v(N, false);
int n, m;
int mnx, mxx, mny, mxy;
int val;
vector<pair<int, int>> coord(N);

void dfs(int u)
{
    v[u] = true;
    mnx = min(mnx, coord[u].first);
    mxx = max(mxx, coord[u].first);

    mny = min(mny, coord[u].second);
    mxy = max(mxy, coord[u].second);

    for (auto w : g[u])
    {
        if (!v[w])
        {
            dfs(w);
        }
    }
}

signed main()
{
    ifstream fin("fenceplan.in");   
    ofstream fout("fenceplan.out");
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        fin >> x >> y;
        coord[i] = {x, y};
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            mnx = INT_MAX;
            mxx = INT_MIN;
            mny = INT_MAX;
            mxy = INT_MIN;
            dfs(i);
            val = 2 * ((mxx - mnx) + (mxy - mny));
            ans = min(ans, val);
        }
    }
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}