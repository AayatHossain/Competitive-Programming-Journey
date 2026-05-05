#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        // prefix bit count
        vector<vector<int>> b(n + 1, vector<int>(32, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 32; j++) {
                b[i][j] = b[i - 1][j];
                if (a[i] & (1LL << j)) {
                    b[i][j]++;
                }
            }
        }

        int q;
        cin >> q;

        while (q--) {
            int l, k;
            cin >> l >> k;

            int low = l, high = n;
            int ans = -1;

            auto ok = [&](int l, int r) {
                int val = 0;
                int len = r - l + 1;

                for (int j = 0; j < 32; j++) {
                    int cnt = b[r][j] - b[l - 1][j];

                    
                    if (cnt == len) {
                        val |= (1LL << j);
                    }
                }

                return val >= k;
            };

            while (low <= high) {
                int mid = (low + high) / 2;

                if (ok(l, mid)) {
                    ans = mid;
                    low = mid + 1;C. Wrong Binary Search

                } else {
                    high = mid - 1;
                }
            }

            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}