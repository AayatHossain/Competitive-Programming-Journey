#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int v1 = n*(n+1); v1%=mod;
        int v2 = (4*n-1); v2%=mod;
        int ans = (((v1*v2)%mod)*337)%mod;

        cout<<ans<<endl; 

    }
}