#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 30;
vector<int> f(N+1, 1);

int inv(int a){
    int b = mod-2;
    int ans =1;
    while(b > 0){
        if(b&1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}

signed main(){
    int t; cin>>t;
    for(int i = 2; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    while(t--){
        int n; cin>>n;
        map<int,int> m;
        int l = 0;
        for(int i = 2; i*i <= n; i++){
            while(n%i == 0){
                n/=i;
                m[i]++;
                l++;
            }
        }
        if(n > 1){
            m[n]++;
            l++;
        }
        // cout<<l<<endl;
        int ans = f[l];
        // cout<<ans<<endl;
        for(auto x: m){
            // cout<<x.first<<" "<<x.second<<endl;
            ans = (ans*inv(f[x.second]))%mod;
        }
        cout<<ans<<" "<<l+1<<endl;
    }
    return 0;
}