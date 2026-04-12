#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        int l = 1;
        int r;
        int ok = 1;
        while (l <= n)
        {
            if (s[l - 1] == '1')
            {
                l++;
                continue;
            }
            else
            {
                r = l;
                while (r + 1 <= n && s[r] == '0')
                {
                    r++;
                }
                if (r - l + 1 == 1)
                {
                    l = r + 1;
                    ok = 0;
                    break;
                }
                for (int i = l; i < r; i++)
                {
                    a[i] = i + 1;
                }
                a[r] = l;
                l = r + 1;
            }
        }
        if (!ok)
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}