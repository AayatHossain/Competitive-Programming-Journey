#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main()
{
    int n, k; cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a[i] = {x,i+1}; 
    }
    vector<int> b(k);
    int s = 0;
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < k; i++){
        b[i] = a[i].second;
        s += a[i].first;
    }
    sort(b.begin(),b.end());

    int ans = 1;
    for(int i = 1; i < k; i++){
        ans = (ans * (b[i]-b[i-1]))%mod;
    }
    cout<<s<<" "<<ans<<endl;

    return 0;
}