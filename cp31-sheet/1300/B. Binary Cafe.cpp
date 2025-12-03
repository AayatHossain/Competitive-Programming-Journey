#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        double n,k; cin>>n>>k;
        cout<<(int)min(n+1,pow(2,k))<<endl;
    }
   
    return 0;
}