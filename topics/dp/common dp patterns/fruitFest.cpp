#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    int t, a, b;
    cin >> t >> a >> b;

    vector<int> f(t + 1, 0);
    f[0] = 1;

    for (int i = a; i <= t; i++) {
        if (f[i - a] == 1) f[i] = 1;
    }
    for (int i = b; i <= t; i++) {
        if (f[i - b] == 1) f[i] = 1;
    }
    for (int i = 0; i <= t; i++) {
        if (f[i] == 1) {
            f[i / 2] = 1;
        }
    }
    for (int i = a; i <= t; i++) {
        if (f[i - a] == 1) f[i] = 1;
    }
    for (int i = b; i <= t; i++) {
        if (f[i - b] == 1) f[i] = 1;
    }

    int ans = 0;
    for (int i = t; i >= 0; i--) {
        if (f[i] == 1) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}
