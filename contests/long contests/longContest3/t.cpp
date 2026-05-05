#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(vector<vector<char>> &g, int si, int sj, int m, int n, vector<vector<int>> &crys)
{
    vector<vector<bool>> vis(m, vector<bool>(n,false));
    queue<pair<int, int>> q;
    int count = 0;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> u = q.front();
            q.pop();
            if (g[u.first][u.second] == 'C')
            {
                count++;
            }
            for (auto dir : directions)
            {
                int nx = u.first + dir.first;
                int ny = u.second + dir.second;
                int valid = nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == false && g[nx][ny] != '#';
                if (valid)
                {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
    q.push({si, sj});
    vis[si][sj] = true;
    crys[si][sj] = count;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> u = q.front();
            q.pop();
            for (auto dir : directions)
            {
                int nx = u.first + dir.first;
                int ny = u.second + dir.second;
                int valid = nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == false && g[nx][ny] != '#';
                if (valid)
                {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    crys[nx][ny] = count;
                }
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int m, n, q;
        cin >> m >> n >> q;
        vector<vector<char>> g(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
            }
        }
        cout << "Case " << c << ":" << "\n";
        c++;
        vector<vector<int>> crys(m, vector<int>(n,-1));
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(crys[x][y] != -1){
                cout<<crys[x][y]<<'\n';
            }else{
                bfs(g, x, y, m, n, crys);
                cout << crys[x][y] << "\n";
            }
            
        }
    }
    return 0;
}
