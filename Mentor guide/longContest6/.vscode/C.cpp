#include<bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c, d, e, f;
const int N = 1e5 + 7;
const int mod = 10000007;
int dp[N];
int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fn(n-1)%mod + fn(n-2)%mod + fn(n-3)%mod + fn(n-4)%mod + fn(n-5)%mod + fn(n-6)%mod;
}
signed main() {
    int n, cases;
    scanf("%lld", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        fill(dp, dp + N, -1);
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", caseno, fn(n) % mod);
    }
    return 0;
}
