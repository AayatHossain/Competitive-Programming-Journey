#include<bits/stdc++.h>
using namespace std;
int mx = 1e7;
signed main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = INT_MAX;
        for(int i = 2; i <= min(n,mx); i++){
            int mod = (n%i != 0);
            ans = min(ans, (i-1)+((n/i)-1)+mod);
        }
        if(ans==INT_MAX)ans=0;
        cout<<ans<<endl;
    }
    return 0;
}