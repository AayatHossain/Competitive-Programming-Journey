#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            int l = 1, r = i;
            int m;
            while(l<=r){
                m = l + (r-l)/2;
                if(a[i-m+1]/m >= 1){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            cout<<r<<" ";
        }
        cout<<'\n';
    }
    return 0;
}