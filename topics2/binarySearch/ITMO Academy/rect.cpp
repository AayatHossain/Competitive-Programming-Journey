#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isSideGood(int w, int h, int n, int x) {
    return (x / w) * (x / h) >= n;
}

signed main(){
    int w,h,n;
    cin>>w>>h>>n;
    int l = 0;  //l is bad
    int r = 1;  //r is good
    while (!isSideGood(w, h, n, r)) {
        r *= 2;
    }
    int mid;
    while(r > l + 1){
        mid = l+(r-l)/2;
    
        if(isSideGood(w, h, n, mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r<<endl;
    
  
    return 0;
}