#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    
    vector<int> level(n+1, -1);
    queue<int> q;
    q.push(1);
    level[1] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    
     bool valid = true;
    for (int i = 1; i < n; i++) {
        if (level[seq[i]] < level[seq[i-1]]) {
            valid = false;
            break;
        }
    }
    
    if (valid) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}