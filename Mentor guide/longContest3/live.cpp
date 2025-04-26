#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,a,b;cin>>n>>a>>b;
        string s; cin>>s;
        int blocks = unique(s.begin(), s.end()) - s.begin();
        int ans1 = a*n + b*n;
        int ans2 = a*n + b*(blocks/2 + 1);
        cout<<max(ans1, ans2)<<endl;
            
    }
}