#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+1;
const int mod = 1e9+7;
#define int long long
vector<int> f(N);
int n,m;

int inv(int a){
    int b = mod-2;
    int res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

signed main(){
    cin>>n>>m;
    f[0]=1;
    f[1]=1;
    for(int i = 2; i <= (n+m); i++){
        f[i] = (f[i-1]*i)%mod;
    }
    int n1 = n+m-1;
    int r1 = n-1;

    int res = (((f[n1]*inv(f[r1]))%mod)*inv(f[n1-r1]))%mod;
    cout<<res<<endl;

    return 0;
}