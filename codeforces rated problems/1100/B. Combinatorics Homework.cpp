#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int a, b, c, m; cin>>a>>b>>c>>m;
        vector<int> v(3);
        v[0] = a; v[1] = b; v[2] = c;
        sort(v.begin(), v.end());
        int mx = (a-1) + (b-1) + (c-1);
        int mn = v[2] - (v[1] + v[0]);
        mn--;
        if(m >= mn && m <= mx){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}