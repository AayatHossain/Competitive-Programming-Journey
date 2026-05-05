#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(vector<int>& a, int mid, int &k) {
    int left = INT_MIN, right = INT_MAX;

    for (int i = 0; i < a.size(); i++) {
        if (i < a.size()-1 && a[i] != -1 && a[i+1] != -1 && abs(a[i] - a[i+1]) > mid) {
            return false;
        }
        if (a[i] == -1) {
            if (i > 0 && a[i-1] != -1) { 
                int low = a[i-1] - mid;
                int high = a[i-1] + mid;
                left = max(left, low);
                right = min(right, high);
            }
            if (i < a.size()-1 && a[i+1] != -1) {  
                int low = a[i+1] - mid;
                int high = a[i+1] + mid;
                left = max(left, low);
                right = min(right, high);
            }
        }
    }
    if(left < 0){
        k = 1;
    }else{
        k = (left+right)/2;

    }
    return right - left >= 0; 
}
signed main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        int l = -1, r = 1e9+7;
        int mid;
        int k=1;
        while(r>l+1){
            mid = l + (r-l)/2;
            if(ok(a,mid, k)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<r<<" "<<k<<endl;
    }

    

    return 0;
}