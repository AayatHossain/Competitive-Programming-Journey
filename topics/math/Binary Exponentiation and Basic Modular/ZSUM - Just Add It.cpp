#include<bits/stdc++.h>
using namespace std;
const int mod = 10000007;
#define int long long
int exp(int a,int b){
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    return res;
}
signed main(){
    int n, k;
    while(cin>>n>>k && !(n==0 && k==0)){
        int v1 = exp(n-1,k);
        int v2 = exp(n,k);
        int v3 = exp(n-1,n-1);
        int v4 = exp(n,n);
        int res = ((2*v1)%mod + v2 + (2*v3)%mod + v4)%mod;
        cout<<res<<endl;
    }
    return 0;
}