#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int l = 1, r = n;
        cout<<n-1<<endl;
        for(int i = 2; i <= n; i++){
            cout<<i<<" "<<l<<" "<<r<<endl;
            r--;
        }
    }
    return 0;
}