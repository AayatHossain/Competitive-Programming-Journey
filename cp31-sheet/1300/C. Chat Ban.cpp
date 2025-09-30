#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(int m, int k, int x){
    if(m <= k){
        int balls = (m*(m+1))/2;
        return balls<x;
    }else{
        int balls1 = (k*(k+1))/2;
        
        int k1 = 2*k -1 ;
        int v1 = k1-k;
        int v2 = k1-m;
        int b1 = (v1*(v1+1))/2;
        int b2 = (v2*(v2+1))/2;

        int balls2 = b1 - b2;

        return balls1+balls2<x;
    }
}
signed main(){
    int t; cin>>t;
    while(t--){
        int k, x; cin>>k>>x;
        int l = 1, r = 2*k-1;
        int m;
        int ans;
        while(l <= r){
            m = l + (r-l)/2;
            if(ok(m,k,x)){
                l=m+1;
            }else{
                ans = m;
                r= m-1;
            }
        }
        cout<<min(ans, 2*k-1)<<endl;
    }
    return 0;
}