#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e4 + 1;
vector<bool> a(10, false);
vector<int> b;
vector<int> du(N, -1);
vector<int> p(N, -1);
vector<bool> vis(N, false);

string rec(int u)
{
    string s;
    while (u != -1)
    {
        s += ('0' + du[u]);
        u = p[u];
    }
    reverse(s.begin(), s.end());
    return s;
}

string bfs()
{
    for (int i = 0; i <= 9; i++)
    {
        if (!a[i])
        {
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end());
    queue<int> q;
    for (auto x : b)
    {
        if (x == 0)
            continue; 
        if (x % n == 0)
            return to_string(x);
        q.push(x % n);
        vis[x % n] = true;
        du[x % n] = x;
        p[x % n] = -1;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u % n == 0)
        {
            string v = rec(u);
            return v;
        }

        for (int d : b)
        {
            int v = (u * 10 + d) % n;
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
                du[v] = d;
                p[v] = u;
            }
        }
    }
    return "-1";
}

signed main()
{
    int c = 1;
    while (cin >> n && n != 0)
    {
        fill(a.begin(), a.end(), false);
        b.clear();
        fill(du.begin(), du.end(), -1);
        fill(p.begin(), p.end(), -1);
        fill(vis.begin(), vis.end(), false);

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a[x] = true;
        }
        string res = bfs();
        cout << "Case " << c << ": " << res << '\n';
        c++;
    }
}