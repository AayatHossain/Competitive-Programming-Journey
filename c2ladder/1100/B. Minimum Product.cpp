#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int ans = LLONG_MAX;
        
            int oa=a,ob=b,on=n;
            int v = min(a - x, n);
            a -= v;
            n -= v;
            b -= min(b - y, n);

            ans=a*b;

            a=oa,b=ob,n=on; 
            v = min(b - y, n);
            b -= v;
            n -= v;
            a -= min(a - x, n);

            ans=min(ans,a*b);
            cout<<ans<<endl;
        
    }
    return 0;
}