#include<bits/stdc++.h>
using namespace std;
signed main(){
    
        int t;
        cin>>t;
        while(t--){
            int a,b,c;
            cin>>a>>b>>c;
            int x=1,y=1,z=1;
            for(int i = 1; i < a; i++){
                x*=10;
            }
            for(int i = 1; i < b; i++){
                y*=10;
            }
            for(int i = 1; i < c; i++){
                z*=10;
            }
            // cout<<x<<" "<<y<<" "<<z<<endl;
            if(z==x || z==y){
                cout<<x<<" "<<y<<endl;
            }else{
                cout<<x<<" "<<y+z<<endl;
            }
        }
        // cout<<gcd(1100,100);
    
    return 0;
}