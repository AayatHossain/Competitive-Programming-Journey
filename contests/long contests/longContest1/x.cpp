#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin>>n;
    int ans = 0;
    while(n > 0){
        n = n / 5;
        ans += n;
    }
    cout<<ans<<endl;
    return 0;
}