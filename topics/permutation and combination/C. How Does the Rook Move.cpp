#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 3e5;
vector<int> f(N+1,1);

int inv(int a){
    int b = mod-2;
    int ans=1;
    while(b > 0){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1 ;
    }
    return ans;
}

int ncr(int n, int r){
    return (((f[n]*inv(f[r]))%mod)*inv(f[n-r]))%mod;
}

signed main(){
    int t; cin>>t;

    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }

    while(t--){
        int n,k; cin>>n>>k;
        int m = n;
        for(int i = 0; i < k; i++){
            int x,y; cin>>x>>y;
            if(x==y)m--;
            else m-=2;
        }
        int ans = 0;
        for(int i = 0; i <= m; i++){
            if((m-i) % 2 == 0 ){
                ans = (ans + ((((ncr(m,i)*f[m-i])%mod)*inv(f[(m-i)/2]))%mod))%mod;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}