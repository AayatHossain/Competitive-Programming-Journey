#include<bits/stdc++.h>
using namespace std;
const int mod = 10;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int res = 1;
        while(b>0){
            if(b&1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            b/=2;
        }
        cout<<res<<endl;
    }
    return 0;
}