#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isGood(int n, int x, int y, int mid) {
//    int items = (mid/x) + (mid/y);
//    return items >= n+1;
     mid = mid - min(x,y);
     int req = (mid/x) + (mid /y);
     n--;
     if(mid < 0 || n < 0){return false;}
     return req >= n;

}

signed main(){
    int n, x,y;cin>>n>>x>>y;
    int l = 0, r = 1e10 + 7;
    int mid;
    while(r > l + 1){
        mid = l + (r-l)/2;
        // cout<<mid<<endl;
        if(isGood(n,x,y,mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r<<endl;
    return 0;
}