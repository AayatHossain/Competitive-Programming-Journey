#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int l,a,b;cin>>l>>a>>b;
        int mx = INT_MIN;
        for(int i = 0; i <= 5000; i++){
            mx = max(mx, (a+b*i)%l);
            // cout<<(a+b*i)%l<<endl;
        }
        cout<<mx<<endl;
    }
}