#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> a(n);
        map<pair<int,int>,int> m;
        int ans =0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            int u = a[i]%x;
            int v = x-u;
            v = v%x;

            int w = a[i]%y;
            ans += m[{v,w}];
            m[{u,w}]++;
        }
        cout<<ans<<endl;
    }
}