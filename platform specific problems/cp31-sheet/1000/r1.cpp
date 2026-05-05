#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==1){cout<<0<<endl;}
        else if(n>=2 && n <= 4){cout<<1<<endl;}
        else if(n >= 5 && n <= 9){cout<<2<<endl;}
        else{
            n = n - 2;
            int q = n / 8;
            // cout<< q*2 + 2<<endl;
            cout<<975461057789971042/2<<endl;
        }
    }
}