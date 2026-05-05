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
        int n;
        cin >> n;
        // int a[n],b[n],c[n],d[n];
        int moves = 0;
        int a, b, c, d;
        for (int i = 0; i < n; i++)
        {
            // cin>>a[i]>>b[i]>>c[i]>>d[i];
            cin >> a >> b >> c >> d;
            if (b > d)
            {
                moves += a + b - d;
            }
            else if (a > c)
            {
                moves += a - c;
            }
            // cout<<moves<<endl;
        }
        cout << moves << endl;
    }
    return 0;
}