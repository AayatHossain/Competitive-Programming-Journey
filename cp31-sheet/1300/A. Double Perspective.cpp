#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return (p[x] == x ? x : p[x] = find(p[x]));
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false; // cycle detected
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> edges(n);
        for (int i = 0; i < n; i++) cin >> edges[i].first >> edges[i].second;

        // DSU size up to 2n because node values ≤ 2n
        DSU dsu(2 * n);

        vector<int> chosen;
        for (int i = 0; i < n; i++) {
            int a = edges[i].first, b = edges[i].second;
            if (dsu.unite(a, b)) {
                chosen.push_back(i + 1); // take this edge, no cycle
            }
            // else skip this edge (it would create a cycle)
        }

        cout << chosen.size() << "\n";
        for (int i = 0; i < (int)chosen.size(); i++) {
            if (i) cout << " ";
            cout << chosen[i];
        }
        cout << "\n";
    }
    return 0;
}
