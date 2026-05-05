#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    double c;cin>>c;
    double l = 0, r = 1e9;
    double mid;
    for(int i = 0; i < 100; i++){
        mid = l + (r-l)/2;
        double val = mid*mid + sqrt(mid);
        int good = (val >=c) ;
        if(good){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<setprecision(16)<<r<<endl;
    return 0;
}