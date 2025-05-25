#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int bits = __popcount(x);
        int extra = n - bits;
        if (x > 1)
        {
            if (n <= bits)
            {
                cout << x << endl;
            }
            else
            {
                if (extra & 1)
                {
                    cout << x + extra + 1 << endl;
                }
                else
                {
                    cout << x + extra << endl;
                }
            }
        }
        else if (x == 1)
        {
            if (n & 1)
            {
                cout << n << endl;
            }
            else
            {
                cout << n + 3 << endl;
            }
        }
        else
        {
            if (n == 1)
            {
                cout << -1 << endl;
            }
            else if (n & 1)
            {
                cout << n + 3 << endl;
            }
            else
            {
                cout << n << endl;
            }
        }
    }
    return 0;
}