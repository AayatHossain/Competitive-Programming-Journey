#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(vector<int> &a, int n, int mid){
    if(a[0] == mid ){
        mid--;
    }else if(a[0] > mid){
        return 0;
    }

    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] == mid){
            mid--;
        }else if(a[i] - a[i-1] > mid){
            return 0;
        }
    }
    return mid >= 0;
}
signed main()
{   int c = 1;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        int l = 0, r = 1e8;
        int mid;
        while(r > l + 1){
            mid = l + (r-l)/2;
            if(ok(a,n,mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<"Case "<<c<<": "<<r<<endl;
        c++;
    }
    
    return 0;
}