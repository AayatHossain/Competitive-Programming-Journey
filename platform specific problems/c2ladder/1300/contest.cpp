#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// count set bits
int beauty(ll x) {
    return __builtin_popcountll(x);
}

// find next number > x such that popcount increases by 1
ll next_with_more_bits(ll x) {
    for (int i = 0; i < 62; i++) {
        if (!(x & (1LL << i))) {
            return x | (1LL << i);
        }
    }
    return (ll)4e18; // fallback (should never really hit)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // min heap: {cost, index}
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        vector<ll> curr = a;

        // initial push
        for (int i = 0; i < n; i++) {
            ll nxt = next_with_more_bits(curr[i]);
            pq.push({nxt - curr[i], i});
        }

        while (!pq.empty() && k > 0) {
            auto [cost, idx] = pq.top();
            pq.pop();

            if (cost > k) break;

            k -= cost;
            curr[idx] += cost;

            ll nxt = next_with_more_bits(curr[idx]);
            pq.push({nxt - curr[idx], idx});
        }

        ll ans = 0;
        for (ll x : curr) ans += beauty(x);

        cout << ans << '\n';
    }

    return 0;
}