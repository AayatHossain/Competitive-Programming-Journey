#include <bits/stdc++.h>
using namespace std;
#define int long long

int ok(vector<int> &a, int n, int mid, int cows){
    int count = 0;
    int curr = -1;
    for(int i = 0; i < n; i++){
        if(a[i] >= curr){
            count++; curr = a[i] + mid;
        }
    }
    return count >= cows;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,c;cin>>n>>c;
        vector<int>a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = 1e9 + 7;
        int mid;
        while(r > l + 1){
            mid = l + (r - l)/2;
            if(ok(a,n,mid,c)){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<l<<'\n';
    }
    

    
    return 0;
}