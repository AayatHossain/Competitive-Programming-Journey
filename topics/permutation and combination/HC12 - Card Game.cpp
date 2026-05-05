#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e4;
vector<int> f(N+1,1);
const int mod = 1e9+7;

int inv(int a){
    int b= mod-2;
    int res = 1;
    while(b>0){
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1; 
    }
    return res;
}

int ncr(int n, int r){
    
    int res = (((f[n]*inv(f[r]))%mod)*inv(f[n-r]))%mod;
    return res;
}

signed main(){
    int t; cin>>t;
    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    int c =1;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++)cin>>a[i];

        int res = 0;
        sort(a.rbegin(),a.rend());
        int ans = 0;
        for(int i = 0; i < n; i++){
            int total = n-(i+1);
            if(total < k-1)break;
            res = (res + a[i]*ncr(total,k-1))%mod;
            // cout<<ncr(total,k-1)<<endl;
   
        }
        cout<<"Case #"<<c<<": "<<res<<endl;
        c++;

    }
    return 0;
}