#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
const int mod = 1e9+7;
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
    int tc = 1;
    while(t--){
        int n, k; cin>>n>>k;
        int n1 = n+k-1;
        int r1 = k-1;
        int res = ((f[n1]*inv(f[r1])%mod)*inv(f[n1-r1]))%mod;
        cout << "Case " << tc << ": " << res << "\n";
        tc++;

    }
    return 0;
}