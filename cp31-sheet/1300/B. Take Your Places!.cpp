#include<bits/stdc++.h>
using namespace std;

// Use long long to prevent overflow
long long f(int n, vector<int> &o, vector<int> &e, int t) {
    // t = 0 implies attempting: Even, Odd, Even, Odd...
    // t = 1 implies attempting: Odd, Even, Odd, Even...

    // 1. Validate if this specific pattern is possible with available counts
    int req_e, req_o;
    if (t == 0) { // Pattern starts with Even
        req_e = (n + 1) / 2; // Ceil(n/2)
        req_o = n / 2;       // Floor(n/2)
    } else {      // Pattern starts with Odd
        req_o = (n + 1) / 2;
        req_e = n / 2;
    }

    // If we don't have exactly the needed counts, this pattern is impossible
    if (e.size() != req_e || o.size() != req_o) {
        return LLONG_MAX;
    }

    long long steps = 0;
    int op = 0, ep = 0;

    for (int i = 0; i < n; i++) {
        // Your logic: if i%2 == t, we use Even, else Odd.
        // t=0 (Start Even): i=0 -> 0==0 (True) -> uses Even. Correct.
        // t=1 (Start Odd):  i=0 -> 0==1 (False)-> uses Odd. Correct.
        if (i % 2 == t) {
            steps += abs(e[ep] - i);
            ep++;
        } else {
            steps += abs(o[op] - i);
            op++;
        }
    }
    return steps;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        vector<int> o, e;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1) {
                o.push_back(i);
            } else {
                e.push_back(i);
            }
        }

        // Global impossibility check
        if (abs((int)o.size() - (int)e.size()) > 1) {
            cout << -1 << endl;
        } else {
            // Calculate cost for both patterns (Start-Even and Start-Odd)
            long long v1 = f(n, o, e, 0);
            long long v2 = f(n, o, e, 1);
            
            // Take the minimum valid cost
            long long ans = min(v1, v2);
            
            if (ans == LLONG_MAX) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}