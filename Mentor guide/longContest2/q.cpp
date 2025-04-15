#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(int mid, vector<int>&a,int n, int m){
    int cut = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid){
            cut += a[i] - mid;
        }
    }
    return cut >=m;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;vector<int>a(n);for(int i = 0; i < n; i++)cin>>a[i];
    int l = 0, r = 1e9;
    int mid;
    while(r > l+1){
        mid = l + (r - l)/2;
        if(ok(mid,a,n,m)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l<<endl;
    
    return 0;
}