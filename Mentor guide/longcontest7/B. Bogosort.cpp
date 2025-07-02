#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}