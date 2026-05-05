#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> a;
vector<int> mainmap(26,0);

bool ok(int index, int k) {
    vector<int> temp = mainmap;

    for(int c = 0; c < 26; c++) {
        temp[c] -= a[index][c];
    }

    vector<int> mapcurr(26);

    for(int c = 0; c < 26; c++) {
        mapcurr[c] = (m - k) * temp[c];
    }

    for(int c = 0; c < 26; c++) {
        if(mapcurr[c] < a[index][c]) return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n, vector<int>(26, 0));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(char c : s){
            a[i][c - 'A']++;
            mainmap[c - 'A']++;
        }
    }

    for(int i = 0; i < n; i++){
        int s = 0, e = m, ans = -1;

        while(s <= e){
            int mid = (s + e) / 2;

            if(ok(i, mid)){
                ans = mid;
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }

        cout << ans << " ";
    }

    cout << endl;
}