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
        vector<int>s(n);
        vector<int> m(n,0);
        int mv = LLONG_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(i > 0){
                m[i] = max(m[i-1],  a[i-1]);
            }
            mv = max(mv, a[i]);
        }
        s[n-1] = a[n-1];
        for(int i = n - 2; i>=0;i--){
            s[i] = s[i+1] + a[i];
        }
        cout<<mv;
        for(int i = n-1; i >= 1; i--){
            cout<<" "<<s[i] + m[i];
        }
        cout<<'\n';

    }
}