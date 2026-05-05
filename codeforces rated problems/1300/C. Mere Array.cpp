#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            mn = min(mn, a[i]);
        }
        vector<int> b = a;
        sort(b.begin(),b.end());
        int f = 1;
        for(int i = 0 ; i < n; i++){

            if(a[i]!=b[i] && gcd(a[i],mn)!=mn){
                f = 0;
                break;
            }
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}