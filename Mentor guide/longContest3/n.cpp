#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(vector<vector<char>> &g, vector<vector<bool>> &vis, queue<pair<pair<int, int>, int>> &giants, vector<vector<int>> &time, int r, int c)
{
    int t = 0;
    while (!giants.empty())
    {
        auto u = giants.front();
        int ux = u.first.first;
        int uy = u.first.second;
        int currTime = u.second;
        giants.pop();
        for (auto v : moves)
        {
            int nx = ux + v.first;
            int ny = uy + v.second;
            int valid = nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != '#'; 
            if (valid)
            {
                if (vis[nx][ny])
                {
                    if (time[nx][ny] > currTime + 1)
                    {
                        giants.push({{nx, ny}, currTime + 1});
                        time[nx][ny] = currTime + 1;
                        vis[nx][ny] = true;
                    }
                }
                else
                {
                    giants.push({{nx, ny}, currTime + 1});
                    time[nx][ny] = currTime + 1;
                    vis[nx][ny] = true;
                }
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<time[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> g(r, vector<char>(c));
        vector<vector<bool>> v(r, vector<bool>(c, false));
        int ji = -1, jj = -1;
        queue<pair<pair<int, int>, int>> giants;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;
                g[i][j] = x;
                if (x == 'J')
                {
                    ji = i;
                    jj = j;
                }
                else if (x == 'F')
                {
                    giants.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> time(r, vector<int>(c, INT_MAX));
        bfs(g, v, giants, time,r,c);
    }
    return 0;
}