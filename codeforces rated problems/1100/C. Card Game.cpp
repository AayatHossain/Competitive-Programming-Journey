#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int f = 0;
        if(s[n-1]=='B'){
            int f2 = 0;
            for(int i = 0; i < n-1; i++){
                if(s[i]=='B'){
                    f2=1;
                    break;
                }
            }
            if(f2)f=1;
            // cout<<f2<<endl;
        }else if(n >= 2 && s[n-2]=='B' && s[0]=='B'){
            f=1;
        }
        if(f){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}