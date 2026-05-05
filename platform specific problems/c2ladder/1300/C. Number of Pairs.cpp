#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,l,r;cin>>n>>l>>r;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int c = 0;
        for(int i =0; i < n-1; i++){
            int i1,i2;
            i1 = lower_bound(a.begin()+i, a.end(), l-a[i]) - a.begin();
            i2 = upper_bound(a.begin()+i, a.end(), r-a[i]) - a.begin();
            i2--;
            if(i1<=i){
                i1=i+1;
            }
            if(i2 > i){
                c += (i2-i1 + 1);
            }
            // cout<<i1<<" "<<i2<<endl;
        }
        cout<<c<<endl;

    }
}