#include<bits/stdc++.h>
using namespace std;
signed main(){
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a=-1,b=-1,c=-1;
        for(int i = 2; i*i < n; i++){
            if(n%i==0){
                a = i;
                n/=i;
                break;
            }
        }

        for(int i = a+1; i*i < n && a!=-1; i++){
            if(n%i==0 && n/i != i){
                b = i;
                c = n/i;
                break;
            }
        }
        // cout<<a<<endl;
        if(c==-1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;

        }
    }
    
    return 0;
}