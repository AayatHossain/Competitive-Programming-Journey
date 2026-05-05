#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string ans = "";
        for(int i = 0 ;i < n; i++){
            string s; cin>>s;
            ans = min(ans+s,s+ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}