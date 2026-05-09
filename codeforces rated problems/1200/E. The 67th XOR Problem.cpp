#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                mx = max(mx, a[i]^a[j]);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}