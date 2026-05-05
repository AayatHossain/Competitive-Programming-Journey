#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char dir[] = {'D', 'L', 'R', 'U'};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    int startX = -1, startY = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                startX = i;
                startY = j;
            }
        }
    }
    
    if (k % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    dist[startX][startY] = 0;
    q.push({startX, startY});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >=0 && ny < m && grid[nx][ny] != '*' && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    string ans;
    int x = startX, y = startY;
    for (int step = 0; step < k; step++) {
        bool found = false;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*') continue;
            if (dist[nx][ny] <= k - step - 1) {
                ans += dir[d];
                x = nx;
                y = ny;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    
    cout << ans << endl;
    return 0;
}