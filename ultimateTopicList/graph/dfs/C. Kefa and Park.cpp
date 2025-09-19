#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, m;
vector<int> a(N + 1);
vector<int> v(N + 1, false);
vector<int> g[N + 1];
int f(int u, int c)
{
    if (c > m)
    {
        // cout<<u<<" "<<c<<endl;
        return 0;
    }
    if (c <= m && g[u].size()==1 && u!=1)
    {
        return 1;
    }
    int ans = 0;
    v[u] = true;
    for (auto w : g[u])
    {
        int fl = c > 0 && a[w];
        if (!v[w])
        {
            if (fl)
            {
                ans += f(w, c + 1);
            }
            else
            {
                ans += f(w, a[w]);
            }
        }
    }
    return ans;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int v = f(1, a[1]);
    cout << v << endl;
    return 0;
}