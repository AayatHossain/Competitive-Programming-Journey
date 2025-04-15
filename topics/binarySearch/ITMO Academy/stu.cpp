#include<bits/stdc++.h>
using namespace std;
#define int long long

int ok(int x, int k, vector<int> &a, int n){
    int minimum = x*k;
    int candidates = 0;
    for(int i = 0; i < n; i++){
        candidates += min(x,a[i]);
    }
    return candidates >= minimum;
}

signed main(){
    int k,n;cin>>k>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    
    int l = 0, r = 1e11 + 7, mid;
    while(r > l+1){
        mid = l + (r-l)/2;
        if(ok(mid, k, a, n)){
            // cout<<l<<" "<<mid<<endl;
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l<<endl;
    
    return 0;
}