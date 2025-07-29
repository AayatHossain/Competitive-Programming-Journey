#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        int f = -1, l = -1;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(i==0)f = a[i];
            if(i==n-1)l = a[i];
        }
        
        int index = unique(a.begin(), a.end()) - a.begin();
        index--;
        map<int, int> m;
        for(int i = 0; i <= index; i++){
            m[a[i]]++;
            // cout<<a[i]<<endl;
        }
        int ans = INT_MAX;
        for(auto x: m){
            int v = x.second-1;
            if(x.first!=f)v++;
            if(x.first!=l)v++;
            ans = min(ans, v);
        }
        
        cout<<ans<<endl;

        
    }
    return 0;
}