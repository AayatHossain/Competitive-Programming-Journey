#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; 
    cin>>t;
    while(t--){
        int a,b,n,m;cin>>a>>b>>n>>m;
        if(a+b < n+m){
            cout<<"NO"<<endl;
        }
        else if(a>=m && b>=n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}