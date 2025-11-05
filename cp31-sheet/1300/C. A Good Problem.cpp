#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; 
    cin>>t;
    while(t--){
        int n,l,r,k;
        cin>>n>>l>>r>>k;
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        if(n&1){
            cout<<l<<endl;
            continue;
        }
        int p = 0;
        for(int i = 0; i < 64; i++){
            if(l&(1LL<<i)){
                p = i;
            }
        }
        int nr = (1<<(p+1));
        if(nr>r){
            cout<<-1<<endl;
        }
        else if(k==n-1 || k==n){
            cout<<nr<<endl;
        }else{
            cout<<l<<endl;
        }
    }
    return 0;
}