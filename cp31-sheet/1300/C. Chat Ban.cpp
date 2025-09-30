#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int m, int k, int x){
    if(m <= k){
        int balls = (m*(m+1))/2;
        return balls < x;  // Note: < instead of <=
    }else{
        int balls1 = (k*(k+1))/2;
        int remaining = m - k;
        
        // Sum of decreasing part: (k-1) + (k-2) + ... + (k-remaining)
        // This is an arithmetic series
        int balls2 = remaining * k - (remaining * (remaining + 1)) / 2;
        
        return (balls1 + balls2) < x;  // Note: < instead of <=
    }
}

signed main(){
    int t; cin>>t;
    while(t--){
        int k, x; cin>>k>>x;
        int l = 1, r = 2*k - 1;
        int ans = 2*k - 1;
        
        while(l <= r){
            int m = l + (r-l)/2;
            if(ok(m, k, x)){
                l = m + 1;
            }else{
                ans = m;
                r = m - 1;
            }
        }
        cout << min(ans, 2*k - 1) << endl;
    }
    return 0;
}