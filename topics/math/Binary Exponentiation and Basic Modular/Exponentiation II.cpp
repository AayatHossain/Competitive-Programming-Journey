#include<bits/stdc++.h>
using namespace std;
#define int long long

const int p = 1e9+7;
const int ps = p-1;

int exp(int a, int b, int mod){
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    
    return res;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;
        int k = exp(b,c,p-1);
        int res = exp(a,k,p);
        // cout<<exp<<" "<<endl;
        cout<<res<<endl;
    }
    return 0;
}