#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int f1 = 0, f2 = 0;
        for(int i = 0; i < n-3; i++){
            string s1 = ""; 
            s1+= s[i];
            s1+=s[i+1];
            s1+=s[i+2];
            s1+=s[i+3];
            if(s1=="2026")f1=1;
            if(s1=="2025")f2=1;
            // cout<<s1<<endl;
        }
        int ans = 0;
        if(f1){
            ans = 0;
        }else if(!f1 && f2){
            ans = 1;
        }else if(!f1 && !f2){
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}