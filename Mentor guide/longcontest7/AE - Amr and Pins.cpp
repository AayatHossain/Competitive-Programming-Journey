#include<bits/stdc++.h>
using namespace std;
// #define int long long
signed main(){
    double r,px,py,qx,qy; cin>>r>>px>>py>>qx>>qy;
    double s = (px-qx)*(px-qx)+(py-qy)*(py-qy);
    double d = sqrt(s);
    double diam = 2*r;
    // int v = (d+2*r)/(2*r) - 1;
    int v = ceil(d / r);
    
    int ans = v/2 + v%2;
    // cout<<d<<" "<<diam<<endl;
    cout<<ans<<endl;
    return 0;
}