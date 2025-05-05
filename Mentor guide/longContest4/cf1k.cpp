#include<bits/stdc++.h>
using namespace std;
bool isSqr(int n){
    int m = sqrt(n);
    return m*m == n;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        if((n%2==0 && isSqr(n/2)) || (n%4==0 && isSqr(n/4))){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}