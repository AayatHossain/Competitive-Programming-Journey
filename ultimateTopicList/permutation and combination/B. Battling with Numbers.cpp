#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main(){
    int n,m;

    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i < n; i++)cin>>a[i];
    for(int i=0;i < n; i++)cin>>b[i];

    cin>>m;
    vector<int> c(m);
    vector<int> d(m);
    for(int i=0;i < m; i++)cin>>c[i];
    for(int i=0;i < m; i++)cin>>d[i];

    int ans = 1;
    if(n < m)ans = 0;
    int i = 0, j = 0;
    while( i < n && j < m){
        if(a[i]!=c[j]){
            ans = (ans*2)%mod;
            i++;
        }else{
            if(b[i] > d[j]){
                ans = (ans*2)%mod;
            }else if(b[i] < d[j]){
                ans = 0;
                break;
            }
            i++;j++;
        }
        // cout<<ans<<endl;
    }
    while( i < n){
        ans = (ans*2)%mod;
        i++;
    }
    if(j < m)ans = 0;
    cout<<ans<<endl;
}