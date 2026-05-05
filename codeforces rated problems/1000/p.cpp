#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int n; cin>>n;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans = (ans * 2)%mod;
    }
    cout<<ans<<endl;
    return 0;
}