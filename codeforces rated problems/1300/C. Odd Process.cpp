#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> odd, even;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            if(x & 1) odd.push_back(x);
            else even.push_back(x);
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int co = odd.size(), ce = even.size();

        // prefix sums for quick largest-k sum
        vector<long long> pe(ce+1, 0);
        for(int i = 1; i <= ce; i++)
            pe[i] = pe[i-1] + even[i-1];

        for(int k = 1; k <= n; k++){
            long long ans = 0;

            if(co == 0){
                ans = 0;
            }
            else{
                long long bestOdd = odd[0];
                int takeEvens = min(ce, k-1);
                ans = bestOdd + pe[takeEvens];
            }

            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}
