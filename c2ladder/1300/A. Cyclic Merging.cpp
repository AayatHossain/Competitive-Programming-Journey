#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mx = LLONG_MIN;
        int s = 0;
        mx=a[n-1];
        for (int i = 0; i < n - 1; i++)
        {
            s += max(a[i], a[i + 1]);
            mx = max(a[i],mx);
        }
        s+=max(a[0],a[n-1]);
        s-=mx;
        cout<<s<<endl;
    }

    return 0;
}