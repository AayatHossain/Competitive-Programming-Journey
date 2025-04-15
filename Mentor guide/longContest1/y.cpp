#include<bits/stdc++.h>
using namespace std;
signed main(){
    long long n; cin>>n;
    long long mod = 1e9 + 7;
    long long ans = pow(2, n);
    cout<<  (int)(ans % mod)<<endl;
    return 0;
}