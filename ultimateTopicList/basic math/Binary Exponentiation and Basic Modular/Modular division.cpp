#include<bits/stdc++.h>
using namespace std;
#define int long long

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
    int a,b,n; cin>>a>>b>>n;
    int bin = exp(b,n-2, n);
    int res = (a*bin)%n;
    cout<<res<<endl;
    return 0;
}