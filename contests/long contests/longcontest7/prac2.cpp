#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int c, n;
    cin >> c >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (c1 <= c2 && c1 + a[i] <= c)
        {
            c1 += a[i];
        }
        else if (c2 < c1 && c2 + a[i] <= c)
        {
            c2 += a[i];
        }
    }
    if (c1 > c2)
    {

        cout << c1 << " " << c2 << endl;
    }
    else
    {
        cout << c2 << " " << c1 << endl;
    }
    return 0;
}