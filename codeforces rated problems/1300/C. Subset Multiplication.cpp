#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        long long ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (b[i + 1] % b[i] != 0) {
                long long g = gcd(b[i], b[i + 1]);
                long long x = b[i + 1] / g; // candidate multiplier
                ans = max(ans, x);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
