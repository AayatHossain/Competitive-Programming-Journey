#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        int s = 0;
        int mn = min(z1,y2);
        s += 2*mn;
        z1 -= mn;
        y2-=mn;

        mn=min(x1,z2);
        x1-=mn;
        z2-=mn;

        mn=min(z1,z2);
        z1-=mn;
        z2-=mn;

        
        mn=min(y1,y2);
        y1-=mn;
        y2-=mn;

        mn=min(y1,x2);
        y1-=mn;
        x2-=mn;

        if(z2 > 0 && y1 > 0){
            mn=min(y1,z2);
            s-=2*mn;
            z2-=mn;
            y1-=mn;
        }
        cout<<s<<endl;
    }
    return 0;
}