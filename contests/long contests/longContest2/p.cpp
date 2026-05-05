#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q;cin>>n>>q;
    vector<int>a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    for(int i = 0; i < q; i++){
        int x;cin>>x;
        int l = -1, r = n;
        int mid;
        while(r > l+1){
            mid = l + (r-l)/2;
            if(a[mid] < x){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(r < n && a[r]==x){
            cout<<r<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }

    
    return 0;
}