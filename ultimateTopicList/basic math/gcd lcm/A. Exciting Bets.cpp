#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        if(a < b){
            int temp = a; a = b; b = temp;
        }
        
        int x,y=LLONG_MAX;
        if(a==b){
            x=0, y=0;
        }else{
            x = a-b; 
            int g=a-b;
            cout<<a%g<<" "<<g-a%g<<endl;
            y = min(a%g, g - a%g);
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}