#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 1e6;
vector<int> f(N+1, 1);

int inv(int a){
    int b = mod-2;
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
int pow2(int a, int b){
    
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

int ncr(int n,int r){
    return (((f[n]*inv(f[r]))%mod)*inv(f[n-r]))%mod;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i =2; i <= N; i++){
        f[i]=(f[i-1]*i)%mod;
    }
    int n;
    while(cin>>n){
        int a,b,d; cin>>a>>b>>d;
        int n1 = ncr(n,a);
        int n2 = ncr(b,d);
        int n3 = pow2(n2, a);
        
        cout<<(n1*n3)%mod<<'\n';
    }
    return 0;
}