#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i =0;i<n; i++)cin>>a[i];
    sort(a.begin(),a.end());
    int q; cin>>q;
    while(q--){
        int m; cin>>m;
        int ub = upper_bound(a.begin(),a.end(), m) - a.begin();
        cout<<ub<<endl;
    }
    return 0;
}