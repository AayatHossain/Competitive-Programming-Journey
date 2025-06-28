#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    int ans = LLONG_MIN / 2;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > t)
        {
            continue;
        }
        if (i != 0)
        {
            curr = p[i - 1];
        }
        int maxVal = curr + t;
        int ub = upper_bound(p.begin(), p.end(), maxVal) - p.begin();
        ub--;
        if (ub >= i)
        {
            ans = max(ans, ub - i + 1);
        }
    }
    if (ans == LLONG_MIN / 2)

    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}