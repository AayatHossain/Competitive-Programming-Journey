#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int l = a[0]-x;
        int r = a[0]+x;
        int c =0;
        for(int i = 0; i < n; i++){
            l = max(l, a[i]-x);
            r = min(r, a[i]+x);
            if(l > r){
                c++;
                l=a[i]-x;
                r=a[i]+x;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}