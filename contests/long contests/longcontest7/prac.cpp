#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        vector<int> s(n);
        vector<int> m(n);
        s[0] = a[0];
        m[0] = a[0];
        // cout<<m[0]<<endl;
        for(int i = 1; i < n; i++){
            int mn = min(m[i-1], a[i]);
            s[i] = s[i-1] + mn;
            m[i] = mn;
        }
        // for(auto x: s){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: m){
        //     cout<<x<<" ";
        // }

        vector<int> mn(n);
        vector<int> mx(n);
        mn[n-1] = a[n-1];
        mx[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--){
            mn[i] = min(a[i], mn[i+1]);
            mx[i] = max(a[i], mx[i+1]);
        }
        // for(auto x: mn){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: mx){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int ans = s[n-1];
        for(int i = 0; i < n-1; i++){
            int nv = a[i] + a[i+1];
            int ns;
            if(nv <= mn[i] ){
           
                ns = s[i] + a[i+1];
            }
            else if(nv == ){
                ns = s[i];
            }
            
            if(ns < s[n-1]){
                ans = min(ans, ns);
            }
            if(i==0){
                cout<<nv<<endl;
                cout<<ns<<endl;
            }
        }
        cout<<ans<<endl;
     
        

    }
    return 0;
}