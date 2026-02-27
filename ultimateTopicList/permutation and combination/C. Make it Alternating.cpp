#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
const int mod = 998244353;
vector<int> f(N+1,1);

int inv(int a){
    int b = mod-2;
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
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
        string s; cin>>s;
        int n = s.size();
        vector<int> b;
        int i = 0,j=0;
        for(j = 1; j < n; j++){
            if(s[j]==s[j-1]){
                continue;
            }else{
                int bs = j-i;
                i = j;
                b.push_back(bs);
            }
        }
        b.push_back(j-i);
        // for(auto x: b){
        //     cout<<x<<" ";
        // }
        int sum = 0;
        int bs = b.size();
        for(int i=0; i < bs; i++){
            if(b[i] > 1){
                sum = sum + (b[i]-1);
            }
        }
        int v1 = 1;
        for(int i = 0; i < bs; i++){
            if(b[i] > 1){
                v1 = (v1*ncr(b[i],b[i]-1))%mod;
            }
        }
        int v2 = f[sum];
        int res = (v1*v2)%mod;
        cout<<n-bs<<" "<<res<<endl;

    }
}