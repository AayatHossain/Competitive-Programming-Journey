#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 1e18;

    auto check = [](int n, int m, int a, int b) -> int {
        int moves = 0;
        int i = a, j = b;
        while (n * m > 1) {
            i = (n + 1) / 2;
            j = (m + 1) / 2;

            int right = (m - j) * n;
            int left = (j - 1) * n;
            int up = (i - 1) * m;
            int down = (n - i) * m;
            vector<pair<int, char>> v = {{right, 'r'}, {left, 'l'}, {up, 'u'}, {down, 'd'}};
            sort(v.begin(), v.end());
            auto x = v.back();
            char c = x.second;
            if (c == 'u') {
                n = n - i + 1;
                i = 1;
            } else if (c == 'd') {
                n = i;
            } else if (c == 'l') {
                m = m - j + 1;
                j = 1;
            } else {
                m = j;
            }
            
            moves++;
        }
        return moves;
    };

    ans = min(ans, check(a, m, a, b));
    ans = min(ans, check(n, b, a, b));
    ans = min(ans, check(n - a + 1, m, a, b));
    ans = min(ans, check(n, m - b + 1, a, b));

    cout << ans+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}