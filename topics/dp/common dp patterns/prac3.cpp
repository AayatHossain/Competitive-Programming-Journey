#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m; cin>>n>>m;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        for(int i = 0; i < n; i++)cin>>b[i];
        int mn = LLONG_MAX;
        for(int i = 0; i < n; i++){
            mn = min(mn, a[i]*b[i]);
        }
        cout<<mn<<'\n';
    }
    return 0;
}