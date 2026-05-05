#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n&1){
            cout<<"YES"<<endl;
            int j=2*n;
            for(int i = 1; i <=n; i+=2){
                cout<<i<<" "<<j<<endl;
                j--;
            }
            int i = 2;
            while(i<j){
                cout<<i<<" "<<j<<endl;
                i+=2;
                j--;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}