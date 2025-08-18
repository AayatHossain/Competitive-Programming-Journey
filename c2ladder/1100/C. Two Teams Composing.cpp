#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        set<int>s;
        map<int,int>m;
        for(int i = 0 ;i < n; i++){
            cin>>a[i];
            m[a[i]]++;
            s.insert(a[i]);
        }
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            int l = s.size()-1;
            int r = m[a[i]];
            if(r>l){mx=max(mx,min(l+1,r-1));}
            else {mx=max(mx,min(l,r));}
        }
        cout<<mx<<endl;
    }
    return 0;
}