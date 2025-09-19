#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 32768;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dist(MOD, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Reverse of increment: from u, we can go to (u-1) mod MOD
        int v1 = (u - 1 + MOD) % MOD;
        if (dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            q.push(v1);
        }
        
        // Reverse of doubling: if u is even, we have two predecessors
        if (u % 2 == 0) {
            int v2 = u / 2;
            int v3 = (u / 2) + (MOD / 2);
            if (dist[v2] == -1) {
                dist[v2] = dist[u] + 1;
                q.push(v2);
            }
            if (dist[v3] == -1) {
                dist[v3] = dist[u] + 1;
                q.push(v3);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dist[a[i]] << " ";
    }
    cout << endl;
    
    return 0;
}