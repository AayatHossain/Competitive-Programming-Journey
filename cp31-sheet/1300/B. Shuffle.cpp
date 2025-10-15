#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,x,m; cin>>n>>x>>m;
        int l = x, r = x;
        for(int i = 0; i < m; i++){
            int nl,nr; cin>>nl>>nr;
            int f = (nl > r || nr < l);
            if(!f){
                l = min(l,nl);
                r = max(r,nr);
            }
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}