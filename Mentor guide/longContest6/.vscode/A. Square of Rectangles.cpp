#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        int flag = 0;
        if(l1==l2 && l2 == l3){
            if(b1+b2+b3==l1)flag = 1;
        }
        if(l1==l2+l3){
            if(b2==b3){
                if(b1+b2==l1)flag = 1;
            }
        }
        if(b1==b2 && b2 == b3){
            if(l1+l2+l3==b1)flag = 1;
        }
        if(b1==b2+b3){
            if(l2==l3){
                if(l1+l2==b1)flag = 1;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;

        }
    }
}