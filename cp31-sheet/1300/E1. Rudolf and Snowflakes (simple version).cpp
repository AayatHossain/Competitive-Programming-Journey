#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int f = 0;
        for(int i = 2; i*i <= n; i++){
            int k = i;
            int m = k+1;
            while(m <= n){
                m = k*m + 1;
                if(m==n){
                    f = 1; 
                    break;
                }
                
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}