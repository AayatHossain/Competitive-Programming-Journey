#include<bits/stdc++.h>
using namespace std;
#define int long long
int ok(int mid, int k, vector<vector<int>> &a){
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        int left = a[i][0];
        int right = a[i][1];
        if(mid > left){
            if(mid > right){
                count += right - left+1;
            }else{
                count += mid - left;
            }
            // count += min(right, mid) - left;
        }
    }
    // cout<<mid<<": "<<count<<endl;
    return count <= k;
}
signed main(){
    int n,k;cin>>n>>k;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin>>a[i][0]>>a[i][1];
    }
    int l = -1e10, r = 1e10;
    int mid;
    while(r > l+1){
        mid = l + (r - l)/2;
        
        if(ok(mid,k,a)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l<<endl;
}