#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> l(n,0);
        multiset<int>s;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        for(int i = 0; i < n; i++){
            cin>>l[i];
        }
        vector<int> b(n,1e6);
        for(int i = 0; i < n; i++){
            if(l[i]){
                b[i]=a[i];
                auto it = s.find(a[i]);
                s.erase(it);
            }
        }
        // for(auto x: s){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: b){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i = 0; i < n; i++){
            if(b[i]!= 1e6)continue;
            // cout<<*s.begin()<<endl;
            b[i] = *s.rbegin();
            auto it = s.find(b[i]);
            s.erase(it);
            
        }
        for(auto x: b){
            cout<<x<<" ";
        }
        cout<<endl;

    }
    return 0;
}