#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;

vector<pair<int,int>> g[N];
vector<int> d(N, LLONG_MAX / 2);
vector<int> results;
int n, m, k;

void f() {
    d[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        for(auto [v, w] : g[u]) {
            int newDist = du + w;

            // Whenever we reach city n, record distance
            if(v == n) {
                results.push_back(newDist);
            }

            if(newDist < d[v]) {
                d[v] = newDist;
                pq.push({newDist, v});
            }
        }

        // stop early if we already found enough paths
        if((int)results.size() >= k) break;
    }

    sort(results.begin(), results.end());
    for(int i = 0; i < min((int)results.size(), k); i++) {
        cout << results[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    f();
    return 0;
}
