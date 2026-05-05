#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(double x,double y,double c, double w){
    double h1 = sqrt(x*x-w*w);
    double h2 = sqrt(y*y-w*w);
    double r1 = 1.0/h1;
    double r2 = 1.0/h2;
    double r3 = 1.0/c;
    return r1+r2 <= r3;
}
signed main(){
    int t;cin>>t;
    int count = 1;
    while(t--){
        double x,y,c; cin>>x>>y>>c;
        double l = 1, r = min(x,y);
        double m;
        for(int i = 0; i < 100; i++){
            m = l+(r-l)/2;
            if(ok(x,y,c,m)){
                l = m;
            }else{
                r = m;
            }
        }
        cout<<"Case "<<count<<": "<<setprecision(12)<<l<<endl;
        count++;
        
    }
    return 0;
}