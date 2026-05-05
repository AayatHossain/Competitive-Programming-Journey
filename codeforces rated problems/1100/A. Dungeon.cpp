#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int a, b, c; cin>>a>>b>>c;
        int mn = min(a, min(b,c));
        int s = a +b+c;
        if(s%9==0){
            if(s/9 <= mn){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
}