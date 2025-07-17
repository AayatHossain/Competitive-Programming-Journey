#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    // dp[i][j] = can we reach i minutes on CD1 and j minutes on CD2
    vector<vector<bool>> dp(c + 1, vector<bool>(c + 1, false));
    dp[0][0] = true;

    for (int s : songs) {
        // loop backwards to avoid overwriting states
        for (int i = c; i >= 0; i--) {
            for (int j = c; j >= 0; j--) {
                if (dp[i][j]) {
                    if (i + s <= c) {
                        dp[i + s][j] = true;
                    }
                    if (j + s <= c) {
                        dp[i][j + s] = true;
                    }
                }
            }
        }
    }

    int best1 = 0, best2 = 0;
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= c; j++) {
            if (dp[i][j]) {
                int sum = i + j;
                int diff = abs(i - j);
                int bestSum = best1 + best2;
                int bestDiff = abs(best1 - best2);
                if (sum > bestSum || (sum == bestSum && diff < bestDiff)) {
                    best1 = max(i, j);
                    best2 = min(i, j);
                }
            }
        }
    }

    cout << best1 << " " << best2 << endl;

    return 0;
}
