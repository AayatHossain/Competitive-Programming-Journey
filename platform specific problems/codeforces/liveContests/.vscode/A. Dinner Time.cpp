#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,m,p,q;cin>>n>>m>>p>>q;
        int leftCells = n%p;
        int blocks = n/p;
        if(leftCells >= 1){
            cout<<"YES"<<endl;
        }else{
            if(blocks*q==m){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}