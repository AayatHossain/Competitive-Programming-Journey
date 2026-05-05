#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[200][200];
pair<int, int> par[200][200];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> aStart;
bool aturn = false;
bool possible = false;
queue<pair<int, int>> q;
int moves = 0;

void bfs()
{
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        int ux = curr.first;
        int uy = curr.second;
        if (aturn && (ux == 0 || ux == n - 1 || uy == 0 || uy == m - 1))
        {
            moves = g[ux][uy] + 1;
            possible = true;
            return;
        }
        q.pop();
        for (auto x : dir)
        {
            int vx = ux + x.first;
            int vy = uy + x.second;
            int valid = vx < n && vx >= 0 && vy < m && vy >= 0;
            // int valid = 1;
            if (valid)
            {
                int uTime = g[ux][uy];
                int vTime = g[vx][vy];
                if (uTime + 1 < vTime)
                {
                    g[vx][vy] = uTime + 1;
                    q.push({vx, vy});
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == 'F')
                {
                    g[i][j] = 0;
                    q.push({i, j});
                }
                else if (c == '#')
                    g[i][j] = 0;
                else if (c == 'J')
                {
                    aStart.first = i;
                    aStart.second = j;
                }
                else if (c == '.')
                    g[i][j] = INT_MAX;
            }
        }
        bfs();
        aturn = true;
        g[aStart.first][aStart.second] = 0;
        q.push({aStart.first, aStart.second});
        bfs();
        if (possible)
        {
            cout << "Case " << c << ": " << moves << '\n';
        }
        else
        {
            cout << "Case " << c << ": " << "IMPOSSIBLE" << '\n';
        }
        c++;
        memset(g, -1, sizeof(g));
        aturn = false;
        possible = false;
        q = queue<pair<int, int>>();
        memset(par, 0, sizeof(par));
    }
}