#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<vector<int>> g(n+1);
        for (int i = 0; i < n; i++) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }

        vector<int> vis(n+1, 0);
        int comps = 0;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                comps++;
                stack<int> st;
                st.push(i);
                vis[i] = 1;
                while (!st.empty()) {
                    int u = st.top(); st.pop();
                    for (int v : g[u]) if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }
        }

        long long ans = 1, base = 2;
        int p = comps;
        while (p) {
            if (p & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            p >>= 1;
        }

        cout << ans << "\n";
    }
    return 0;
}
