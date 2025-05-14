#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int c = 1;
    int t; cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        cout<<"Case "<<c<<":"<<endl;
        c++;
        for(int i = 0; i < q; i++){
            int s,e; cin>>s>>e;
            int left = lower_bound(a.begin(), a.end(), s) - a.begin();
            int right = upper_bound(a.begin(), a.end(), e) - a.begin();
            cout<<right-left<<endl;
        }
    }
    return 0;
}