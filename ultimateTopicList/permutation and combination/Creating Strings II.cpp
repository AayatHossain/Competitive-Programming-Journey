#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
const int mod = 1e9+7;
vector<int> f(N+1);
int modinv(int a){
    int b = mod-2;
    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = (b>>1);
    }
    // cout<<res<<" ";
    // if(a==6){
    //     cout<<res<<endl;
    // }
    return res;
}
signed main(){
    string s; cin>>s;
    int n = s.size();
    f[0]=1;
    f[1]=1;
    for(int i  =1; i <= N; i++){
        f[i] = (f[i-1]*i)%mod;
    }
    vector<int> cnt(26,0);
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
        // cout<<cnt[s[i]-'a'];
    }
    int ans = f[n];
    for(int i = 0; i < 26; i++){
        if(cnt[i]>0){
            ans = (ans * modinv(f[cnt[i]]))%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}