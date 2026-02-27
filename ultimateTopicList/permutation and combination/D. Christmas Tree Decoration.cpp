#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
const int mod = 998244353;
vector<int> f(N+1,1);

int inv(int a){
    int b = mod-2;
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}

signed main(){
    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        int each = 0;
        for(int i = 0; i <= n; i++){
            cin>>a[i];
            each+=a[i];
        }
        each /= n;

        int ok = 1;
        int zeroes = 0;
        for(int i = 1; i <= n; i++){
            int rem = min(a[i],each);
            a[i] -= rem;
            a[0] -= (each - rem);
            if(a[i] > 1 || a[0] < 0){
                ok = 0;
                break;
            }
            if(a[i]==0)zeroes++;
        }
        if(a[0] > zeroes){
            ok = 0;
        }
        int ans = 0;
        int pick = zeroes;
        int nopick = zeroes - a[0];
        
        if(ok){
            ans = (((f[pick]*inv(f[pick - nopick]))%mod)*f[n-nopick])%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}