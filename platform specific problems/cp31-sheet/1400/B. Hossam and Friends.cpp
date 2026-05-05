#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(vector<int>& a) {
        n = a.size() - 1;
        tree.resize(4 * n);
        build(1, 1, n, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return LLONG_MAX;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    int get(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> rm(n + 1, LLONG_MAX);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            rm[x] = min(rm[x], y);
        }

        SegTree st(rm);

        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int l = 1, r = i;
            int optimal = i;

            while (l <= r) {
                int mid = (l + r) / 2;
                if (st.get(mid, i) > i) {
                    optimal = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans += (i - optimal + 1);
        }

        cout << ans << '\n';
    }

    return 0;
}