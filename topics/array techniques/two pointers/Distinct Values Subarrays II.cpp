#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> m;
    int j = 0;
    int ans = 0;
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[a[i]] == 0)
            d++;
        m[a[i]]++;
        while (j <= i && d > k)
        {
            m[a[j]]--;
            j++;
            if (m[a[j-1]] == 0)
                d--;
            // if (i == 2)
            // {
            //     cout<<d<<endl;
            // }
        }

        ans += i - j + 1;
    }
    cout << ans << endl;
    return 0;
}