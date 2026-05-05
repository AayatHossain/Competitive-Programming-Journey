#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
signed main(){
    int f[N+1];
    f[0]=1;
    for(int i = 1; i <= N; i++){
        f[i] = f[i-1]*i;
    }
    int n; cin>>n;
    int r = n/2;
    int ncr = f[n]/(f[r]*f[n-r]);
    int organizations = f[r-1];
    int ans = (ncr * organizations * organizations)/2;
    cout<<ans<<endl;
    return 0;
}