#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
vector<int> f(N+1,1);
const int mod = 1e9+7;
int a,b,n; 

bool valid(int v){
    while(v > 0){
        int x = v%10;
        if(!(x==a || x==b))return false;
        v /= 10;
    }
    return true;
}

int inv(int a){
    int b = mod-2;
    int res = 1;
    while(b > 0){
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1; 
    }
    return res;
}

int perm(int n1,int n2){
    int total = n1+n2;
    int res = (((f[total] * inv(f[n1]))%mod)*inv(f[n2]))%mod;
    return res;
}

signed main(){
    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    cin>>a>>b>>n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int x = i;
        int y = n-x;
        int v = a*x + b*y;
        if(valid(v)){
            ans = (ans + perm(x,y))%mod;
        }
    }
        cout<<ans<<endl;

    return 0;
}