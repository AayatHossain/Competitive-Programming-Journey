#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        if(n%4==0){
            cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        }else if(n%2){
            cout<<n/2<<" "<<n/2<<" "<<1<<endl;
        }else{
            cout<<2<<" "<<n/2 - 1<<" "<<n/2 -1<<endl;
        }
    }
    return 0;
}