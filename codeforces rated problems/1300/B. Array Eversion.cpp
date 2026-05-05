#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        int c = 0;
        int curr = a[n-1];
        for(int i = n-2; i >= 0; i--){
            if(a[i] > curr){
                curr = a[i];
                c++;
            }
        }
        cout<<c<<endl;
    }
}