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
        int i = 0, j = 1;
        int mx = LLONG_MIN / 2;
        int c = 1;
        pair<int, int> pi;
        while (i < n && j < n)
        {
            if (a[i] == a[j])
            {
                c = 1;
                while (j < n && a[i] == a[j])
                {
                    c++;
                    j++;
                }
                if (c > mx)
                {
                    pi = {i, j - 1};
                    mx = c;
                }
                i = j - 1;
            }
            else
            {
                i++;
                j++;
            }
        }
        pi.first++;
        pi.second++;
        // cout << pi.first << " " << pi.second << endl;
        int ans = 0;
        i = pi.first;
        j = pi.second;
        int left = 0, right = 0;
        int k = j - i + 1;

        left = i - 1;
        right = n - j;
        if (left < right)
        {
            int ktemp = k;
            while (i > 1)
            {
                ans++;
                i -= ktemp;
                ktemp *= 2;
            }
            while (j < n)
            {
                // cout<<j<<endl;
                ans++;
                j += ktemp;
                ktemp *= 2;
            }
        }
        else
        {
            int ktemp = k;
            while (j < n)
            {
                // cout<<j<<endl;
                ans++;
                j += ktemp;
                ktemp *= 2;
            }
             while (i > 1)
            {
                ans++;
                i -= ktemp;
                ktemp *= 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}