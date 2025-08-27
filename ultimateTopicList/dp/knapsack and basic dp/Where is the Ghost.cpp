#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

signed main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= 2520; // only need mod 2520
    }

    // dp[i][prod] = number of ways using first i elements (0..i-1) to get product = prod
    vector<vector<int>> dp(n+1, vector<int>(2520, 0));

    // Base case: before choosing anything, product = 1 (multiplicative identity)
    dp[0][1] = 1;

    // Forward iteration
    for(int i = 0; i < n; i++){
        for(int prod = 0; prod < 2520; prod++){
            // Option 1: skip a[i]
            dp[i+1][prod] = (dp[i+1][prod] + dp[i][prod]) % mod;

            // Option 2: take a[i]
            int newProd = (prod * a[i]) % 2520;
            dp[i+1][newProd] = (dp[i+1][newProd] + dp[i][prod]) % mod;
        }
    }

    int ans = dp[n][0]; // final product divisible by 2520
    cout << ans % mod << endl;
    return 0;
}
