#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;

int f(vector<int> arr, vector<int> selected) {
    queue<int> q;
    vector<int> vis(n, 0);
    for (int idx : selected) {
        q.push(idx);
        vis[idx] = 1;
    }
    int last = 0;
    while (!q.empty()) {
        int i = q.front(); q.pop();
        last = arr[i];
        if (i > 0 && !vis[i - 1]) {
            vis[i - 1] = 1;
            q.push(i - 1);
        }
        if (i < n - 1 && !vis[i + 1]) {
            vis[i + 1] = 1;
            q.push(i + 1);
        }
    }
    return last;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) p.push_back({a[i], i});
        sort(p.rbegin(), p.rend());
        long long ans = 0;
        for (int i = 0; i + k <= n; i++) {
            vector<pair<int, int>> win(p.begin() + i, p.begin() + i + k);
            vector<int> b = a;
            vector<int> sel;
            long long sum = 0;
            for (auto &x : win) {
                sum += x.first;
                sel.push_back(x.second);
                b[x.second] = -1;
            }
            int last = f(a, sel);
            ans = max(ans, sum + last);
        }
        cout << ans << "\n";
    }
}
