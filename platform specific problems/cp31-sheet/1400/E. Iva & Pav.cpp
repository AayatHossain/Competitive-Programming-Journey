#include<bits/stdc++.h>
using namespace std;

bool ok(int m, int l, int n, vector<vector<int>> &b, int k){
    int v = 0;
    for(int i = 0; i < 32; i++){
        int bits = b[m][i] - b[l-1][i];
        if(bits == (m-l+1)){
            v = (v | (1<<i)) ;
        }
    }
    if(v >= k)return true;
    return false;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1 ; i <= n; i++){
            cin>>a[i];
        }


        vector<vector<int>> b(n+1,vector<int>(32,0));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 32; j++){
                int ison = (a[i]&(1<<j));
                if(ison != 0)ison = 1;
                b[i][j] = b[i-1][j] + ison;
            }
        }
        // for(auto x: b[n]){
        //     cout<<x<<" ";
        // }
        int q; cin>>q;
        while(q--){
            int left,k; cin>>left>>k;
            int l = left, r = n;
            int m;
            int ans = INT_MIN;
            while(l <= r){
                m = l + (r-l)/2;
                if(ok(m,left,n,b,k)){
                    ans = max(m, ans);
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
           
            if(ans==INT_MIN)ans=-1;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}