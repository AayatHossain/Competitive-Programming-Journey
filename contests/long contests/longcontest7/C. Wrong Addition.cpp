#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, s;
        cin >> a >> s;
        int n = a.size();
        int m = s.size();
        int i = n - 1, j = m - 1;
        string b;
        int f = 1;
        while (j >= 0 || i >= 0)
        {
            int v1, v2;
            if (i < 0)
            {
                v1 = 0;
            }
            else
            {
                v1 = a[i] - '0';
            }
            if (j < 0)
            {
                v2 = 0;
            }
            else
            {
                v2 = s[j] - '0';
            }
            // int v2 = s[j] - '0';
            if (v2 >= v1)
            {
                int v = v2 - v1;
                b += v + '0';
                j--;
                i--;
            }
            else
            {
                v2 = s[j - 1] - '0';
                v2 = v2 * 10 + (s[j] - '0');
                int v = v2 - v1;
                if (v < 0 || v > 9)
                {
                    f = 0;
                    break;
                }
                b += v + '0';
                j -= 2;
                i--;
            }
        }
        if (f)
        {
            reverse(b.begin(), b.end());
            int start = 0;
            for (int i = 0; i < b.size(); i++)
            {
                if (b[i] != '0')
                {
                    start = i;
                    break;
                }
            }
            for (int i = start; i < b.size(); i++)
            {
                cout << b[i];
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}