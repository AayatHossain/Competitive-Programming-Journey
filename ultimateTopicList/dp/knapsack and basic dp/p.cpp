#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int l, r; cin>>l>>r;
        int n = r-l+1;
        int ans;
        if(l==r){
            ans = l;
        }else{
            ans = (n-2) + gcd(l,r) + r;
        }
        cout<<ans<<'\n';
        // cout<<f2(l,r)<<endl;
    }
    return 0;
}