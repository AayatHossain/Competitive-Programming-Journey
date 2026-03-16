#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b,c,m; cin>>a>>b>>c>>m;
        int l = lcm(a,lcm(b,c));
        int lcnt = m/l;

        int abl = lcm(a,b);
        int abcnt = m/abl;

        int bcl = lcm(b,c);
        int bccnt = m/bcl;

        int cal = lcm(c,a);
        int cacnt = m/cal;

        int alice = 0, bob = 0, carol = 0;

        
        cout<<l<<endl;
        cout<<lcnt<<endl;
        cout<<abl<<endl;
        cout<<abcnt<<endl;


    }
    return 0;
}