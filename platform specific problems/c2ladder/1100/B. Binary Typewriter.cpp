#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int c = 0;
        if(s[0]=='1')c++;
        for(int i = 1; i < n; i++){
            if(s[i]!=s[i-1])c++;
        }
        // cout<<c<<endl;
        int ans;
        if(c>=3){
            ans = c-2+n;
        }else if(c==2){
            ans = c-1+n;
        }else{
            ans = c+n;
        }
        cout<<ans<<endl;
    }
    return 0;
}