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
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        vector<vector<long long>> a(n, vector<long long>(n, -1));

        int cx = n / 2; // center row
        int cy = n / 2; // center col
        if(n%2==0){
            cx--;
            cy--;
        }
        long long val = 0;
        a[cx][cy] = val++;

        // directions: right, down, left, up
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int step = 1;
        while (val < 1LL * n * n) {
            for (int dir = 0; dir < 4; dir++) {
                for (int i = 0; i < step && val < 1LL * n * n; i++) {
                    cx += dx[dir];
                    cy += dy[dir];
                    if (cx >= 0 && cx < n && cy >= 0 && cy < n)
                        a[cx][cy] = val++;
                }
                if (dir % 2 == 1) step++; // increase step after down and up
            }
        }

        // print matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
