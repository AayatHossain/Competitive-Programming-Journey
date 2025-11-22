#include<bits/stdc++.h>
using namespace std;
int n,x,y;
bool ok(int m ){
    return (m/x + m/y) > n;
}
signed main(){
    cin>>n>>x>>y;
    
    int l = 0, r = 1e9;
    int m; 
    while(l+1 < r){
        m = l + (r-l)/2;
        if(ok(m)){
            r = m;
        }else{
            l = m;
        }
    }
    
    cout<<r<<endl;
    return 0;
}