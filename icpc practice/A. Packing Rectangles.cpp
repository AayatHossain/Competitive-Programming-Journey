#include<bits/stdc++.h>
using namespace std;
#define int long long
int w,h,n;
bool ok(int m){
    return (m/w)*(m/h) >= n;
}
signed main(){
    cin>>w>>h>>n;
    int l = 0, r=1;
    while(!ok(r)){
        r*=2;
    }
    int m;
    int ans = r;
    while(l<=r){
        m = l+(r-l)/2;
        if(ok(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}