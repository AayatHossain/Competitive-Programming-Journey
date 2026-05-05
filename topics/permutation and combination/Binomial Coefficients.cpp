#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int modinv(int a){
    int b = mod-2;
    int res = 1;
    while(b){
        if(b & 1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = (b>>1);
    }
    return res;
}

int ncr(int n,int r, vector<int> &f){
    if(r < 0 || r > n)return 0;

    return (((f[n]*modinv(f[r]))%mod)*(modinv(f[n-r])))%mod;
}

signed main() {
    int n; 
    cin >> n;
    int v = 1e6;
    vector<int> f(v + 1);
    f[0] = 1;
    for (int i = 1; i <= v; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }

    for(int i = 1; i <= n; i++){
        int a,b; cin>>a>>b;
        cout<<ncr(a,b,f)<<endl;

    }

    return 0;
}
