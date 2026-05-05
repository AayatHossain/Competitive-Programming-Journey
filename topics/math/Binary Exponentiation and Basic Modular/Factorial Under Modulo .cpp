#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define int long long
signed main(){
    int n; cin>>n;
    int r = 1;
    for(int i = 2; i <= n; i++){
        r = (r * i)%mod;
    }
    cout<<r<<endl;
    return 0;
}