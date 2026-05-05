#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int val){
    if(val==2){
        return true;
    }

    for(int i = 2; i*i <= val; i++){
        if(val%i == 0){
            return false;
        }
    }
    return true;
}

signed main(){
    int t;cin>>t;
    while(t--){
        int d;cin>>d;
        int init = 1;
        int p = -1,q=-1;
        int val = 1+d;
        while(1){
           
            if(prime(val) && p==-1){
                p = val;
            }else if(prime(val) && p != -1){
                q = val;break;
            }
            val += d;
        }
        // cout<<p<<q<<endl;
        cout<<min(p*q, p*p*p)<<endl;
        
    }
    return 0;
}