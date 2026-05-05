#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6+1;
vector<int> fac(M);
const int mod = 1e9+7;
void calcFactorial(){
    fac[1] = 1;
    for(int i = 2; i <= M; i++){
        fac[i] = (fac[i-1]*i)%mod;
    }
}
signed main(){
    calcFactorial();
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += fac[a[i]]%mod;
            ans %= mod;
        }
        cout<<ans<<endl;
    }

}