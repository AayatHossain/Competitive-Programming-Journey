#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int m = 0;
        int t = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='M'){
                m++;
            }
            if(s[i]=='T'){
                t++;
            }
        }
        int c = 0;
        int f = 1;
        if(t < 2*m || t > 2*m){
            f = 0;
        }

        for(int i = 0; i < n && f; i++){
            if(s[i]=='T'){
                c++;
            }else{
                c--;
            }
            if(c < 0 || c > m){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}