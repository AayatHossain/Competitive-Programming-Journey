#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(vector<pair<int,int>> a, int k){
    int rl = 0, rr = 0;
    for(auto x: a){
        int l = x.first;
        int r = x.second;
        rl = rl - k;
        rr = rr + k;
        if(rr < l || rl > r){
            return false;
        }else{
            rl = max(l,rl);
            rr = min(rr, r);
        }
    }
    return true;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++){
            int x, y; cin>>x>>y;
            a[i] = {x,y};
        }
        int l = -1, r = 1e10;
        int mid;
        while(r > l + 1){
            mid = l + (r-l)/2;
            if(ok(a,mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<r<<endl;
    } 
    return 0;
}