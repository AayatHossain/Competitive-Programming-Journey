#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;cin>>n;vector<int>a(n);for(int i = 0; i < n; i++)cin>>a[i];
    int q;cin>>q;
    for(int i = 0; i < q; i++){
        int x;cin>>x;
        int l = lower_bound(a.begin(),a.end(), x) - a.begin();
        int r = upper_bound(a.begin(),a.end(), x) - a.begin();
        l--;
        if(l<0){
            cout<<"X"<<" ";
        }else{
            cout<<a[l]<<" ";
        }
        if(r==n){
            cout<<"X"<<endl;
        }else{
            cout<<a[r]<<endl;
        }
        
    }
    return 0;
}