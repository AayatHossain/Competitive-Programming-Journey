#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int l,r; cin>>l>>r;
        int x=-1,y=-1;
        if(l==1){
            x=1;y=2;
        }else{
            if(lcm(l,2*l) <= r && 2*l <= r){
                x = l; y = 2*l;
            }
        }
        cout<<x<<" "<<y<<endl;
        
    }
    return 0;
}