#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> p(n);
        p[0]=a[0];
        for(int i = 1; i < n; i++){
            p[i] = p[i-1] + a[i];
        }
        int s = p[n-1];

        for(int i = 0; i < q; i++){
            int l, r, k; cin>>l>>r>>k;
            l--;r--;
            if(l >= 1){
                int ps = p[r] - p[l-1];
                int cs = (r-l+1)*k;
                int ns = s + (cs - ps);

                // if(i==0){
                //     cout<<ns<<" "<<cs<<" "<<ps<<endl;
                // }

                if(ns&1){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                int ps = p[r];
                int cs = (r-l+1)*k;
                int ns = s + (cs - ps);
                if(ns&1){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}