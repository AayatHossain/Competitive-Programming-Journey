#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int x,y,k;cin>>x>>y>>k;
        int req1 = k + k*y;
        int req2 = (k-1) + k*y;
        int ans = LLONG_MAX;
        
        if(req1 - k*y >= 0){
            int den = x - 1;
            int moves = (req1+den-1)/den;
            int res = moves + k;
            ans = min(ans, res);
        }
        if(req2 - k*y >= 0){
            int den = x - 1;
            int moves = (req2+den-1)/den;
            int res = moves + k;
            ans = min(ans, res);
        }
        cout<<ans<<endl;
    }
    return 0;
}