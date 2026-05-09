#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int t,h,u;
        cin>>t>>h>>u;

        int tu = min(t,u);
        t -= tu;
        u -= tu;

        // int tht = 0;
        // while(h>=1 && t>=2){
        //     tht++;
        //     h--;
        //     t-=2;
        // }

        int th = min(t,h);
        t -= th;
        h -= th;


        int ans = 3*u + 3*h + 4*tu + 5*th ;
        if(t>0) ans += 2*t+1;
        cout<<ans<<endl;


    }

    return 0;
}