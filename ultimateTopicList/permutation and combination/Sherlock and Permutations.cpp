#include <bits/stdc++.h>
#define int long long
using namespace std;

int inv(int a){
    int mod = 1e9+7;
    int b = mod-2;
    int res = 1;
    while(b > 0){
        if(b&1)res = (res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

int solve(int n, int m) {
    if(m==0)return 0;
    if(m==1)return 1;
    
    int total = n+m-1;
    int mod = 1e9+7;
    vector<int> f(total+1,1);
    for(int i = 2; i <= total; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    // cout<<f[total]<<endl;
    // cout<<f[n]<<endl;
    // cout<<f[m-1]<<endl;
    // cout<<f[total]/(f[n]*f[m-1])<<endl;;
    int res = (((f[total] * inv(f[n]))%mod) * inv(f[m-1]))%mod;
    return res;
    
}

signed main()
{
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        cout<<solve(n,m)<<endl;
    }

    return 0;
}