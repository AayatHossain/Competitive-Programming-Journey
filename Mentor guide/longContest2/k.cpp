#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(int balance, int rows){
    int req = rows*(rows + 1) / 2;
    return balance >= req;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int l = 0, r = 1e9;
        int mid;
        while(r > l+1){
            mid = l + (r - l) / 2;
            if(ok(n, mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<l<<endl;
    }


    
    return 0;
}