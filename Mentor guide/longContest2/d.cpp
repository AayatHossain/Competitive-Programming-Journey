#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(int n, int mid){
    int req = mid*(mid + 1) / 2;
    return req <= n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int l = 0, r = 1e9;
        int mid;
        while(r > l+1){
            mid = l + (r - l) / 2;
            if(ok(n, mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<l<<endl;
    }


    
    return 0;
}