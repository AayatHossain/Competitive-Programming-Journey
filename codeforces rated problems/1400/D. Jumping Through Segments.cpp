#include<bits/stdc++.h>
using namespace std;

bool ok(int k, vector<pair<int,int>> &a, int n){
    int cl = 0, cr = 0;
    for(int i = 0; i < n; i++){
        int l = a[i].first;
        int r = a[i].second;
        
        cl = max(l, cl - k);
        cr = min(r, cr + k);

        if(cl > cr)return false;
    }
    return true;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++){
            int x,y; cin>>x>>y;
            a[i] = {x,y};
        }
        int l = 0, r = 1e9;
        int ans = INT_MAX;
        while(l <= r){
            int m = l + (r-l)/2;
            if(ok(m,a,n)){
                ans = min(ans, m);
                r = m-1;
            }else{
                l = m+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}