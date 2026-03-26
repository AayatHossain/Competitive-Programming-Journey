#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 5;

vector<bool> isPrime(MAXN, true);
vector<int> cnt(MAXN, 0);

void sieve(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int max_n = 0;
    vector<int> tests(t);
    for (int i = 0; i < t; i++) {
        cin >> tests[i];
        max_n = max(max_n, tests[i]);
    }

    // Step 1: Sieve
    sieve(max_n);

    // Step 2: Count multiples
    for (int i = 2; i <= max_n; i++) {
        for (int j = i + i; j <= max_n; j += i) {
            int k = j / i;
            if (isPrime[k]) {
                cnt[j]++;
            }
        }
    }

    // Step 3: Prefix answers
    vector<int> ans(max_n + 1, 0);

    for (int i = 2; i <= max_n; i++) {
        ans[i] = ans[i - 1] + cnt[i];
        if (isPrime[i]) ans[i]++; // for (1, i)
    }

    // Output
    for (int n : tests) {
        cout << ans[n] << '\n';
    }

    return 0;
}