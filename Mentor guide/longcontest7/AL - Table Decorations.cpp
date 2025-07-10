#include <bits/stdc++.h>
using namespace std;
signed main()
{
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = a[0];
    for (int i = 1; i < 3; i++)
    {
        a[i] -= a[0];
    }
    int p = a[2] / 2;
    if (a[1] == a[2])
    {
        ans += (a[1] + a[2]) / 3;
    }
    else
    {
        if (p > a[1])
        {
            ans += a[1];
        }
        else if (p <= a[1])
        {
            int l1 = a[2] % 2;
            int l2 = a[1] - p;
            if (l1 > 0 && l2 > 0 && l1 + l2 >= 3)
            {
                ans++;
            }
            ans += p;
        }
    }

    cout << ans << endl;

    return 0;
}