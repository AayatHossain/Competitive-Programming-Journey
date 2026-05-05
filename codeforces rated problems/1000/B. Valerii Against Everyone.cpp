#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(b.rbegin(), b.rend());
        int f = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = b[i];
            bitset<1000> y; // Assuming numbers are within 0 to 63. Adjust size if needed.
            for (int j = i + 1; j < n; j++) {
                y.set(b[j]); // Set the bit at position b[j]
                if (x == y.to_ullong()) { // Convert bitset to unsigned long long and compare
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        if (f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}