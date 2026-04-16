#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            if(a[i] & 1){
                a[i] = a[i] + (a[i]%10);
            }
        }

        map<int, int> mp;

        int mx = a.back();
        mp[mx] = 0;

        int cur = mx;
        for (int i = 0; i < 10; i++) {
            cur = cur + (cur % 10);
            mp[cur] = 0;
        }

        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        for (int i = 0; i < n-1; i++) {
            int x = a[i];

            if(x%10 == 0){
                if (mp.count(x)) {
                    mp[x]++;
                  
                }
                  continue;
            }


            // if (x % 2 == 1) {

            //     if (mp.count(x)) {
            //         mp[x]++;
            //         continue;
            //     }else{
            //         x += (x%10);
            //     }
                
            // }

            for (auto &it : mp) {
                int y = it.first;
                if (y >= x) {
                    int m = (y - x) / 20;
                    int nx = x + m * 20;
                    if (nx == y) {
                        // cout<<x<<" "<<nx<<endl;
                        mp[y]++;
                        break;
                    }
                }
            }
        }
        // cout<<mp[22]<<endl;
        // bool ok = false;
        int cnt = 0;
        for(auto x: mp){
            // cout<<x.first<<" ";
            cnt += x.second;
        }
        // cout<<endl;
        if(cnt+1 == n){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}