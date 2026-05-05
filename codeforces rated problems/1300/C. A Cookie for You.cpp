#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; 
    cin>>t;
    while(t--){
        int a,b,n,m;cin>>a>>b>>n>>m;
        if(a+b >= n+m && m <= min(a,b)){
            cout<<"Yes"<<endl;
        }
        
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}