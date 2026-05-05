#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        if(lcm(a,b)==b){
            cout<<lcm(a,b)*(b/a)<<endl;
        }else{
            cout<<lcm(a,b)<<endl;
        }
    }
    return 0;
}