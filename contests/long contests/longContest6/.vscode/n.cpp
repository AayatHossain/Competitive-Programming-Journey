#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(2, -1));

    for(int curr_k = 0; curr_k <= k; curr_k++) {
        for(int t = 0; t < 2; t++) {
            if(curr_k == 0) {
                dp[curr_k][t] = 0;
                continue;
            }

            int win = 0;
            for(int i = 0; i < n; i++) {
                if(curr_k - a[i] == 0) {
                    win = 1;
                    break;
                }
                if(curr_k - a[i] < 0) continue;
                if(dp[curr_k - a[i]][!t] == 0) {
                    win = 1;
                    break;
                }
            }
            dp[curr_k][t] = win;
        }
    }

    if(dp[k][1]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}