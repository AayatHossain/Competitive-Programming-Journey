#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int s,k,m; cin>>s>>k>>m;
        int flips = m/k;
        int left = m%k;
        int top = -1;
        if(k>=s){
            top = s;
        }else{
            if(flips&1){
                top = k;
            }else{
                top = s;
            }
        }
        if(left > top){
            cout<<0<<endl;
        }else{
            cout<<top-left<<endl;
        }
        
    }
    return 0;
}