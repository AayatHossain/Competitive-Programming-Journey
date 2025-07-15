#include<bits/stdc++.h>
using namespace std;
#define int long long
int ok(vector<int> &a, int h, int k, int n){
    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] >= k){
            h-=k;
        }else{
            h -= a[i] - a[i-1] ;
        }
        // cout<<h<<endl;
    }
    h-=k;
    return h<=0;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n,h;cin>>n>>h;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int l = 0, r = h;
        int mid;
        while(r > l+1){
            mid = l + (r-l)/2;
            if(ok(a,h,mid,n)){
                r = mid;
            }else{
                l = mid;
            }
            
        }
        cout<<r<<endl;
    }
    return 0;
}