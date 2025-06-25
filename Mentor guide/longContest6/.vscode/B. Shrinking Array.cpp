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
        {
            cin >> a[i];
        }
        int moves = -1;

        for (int i = 0; i < n - 1; i++)
        {
            
            int l = min(a[i], a[i + 1]);
            int r = max(a[i], a[i + 1]);
            if (abs(a[i] - a[i + 1]) <= 1)
            {
                moves = 0;
                break;
            }
            
        }

        for (int i = 0; i < n - 1 && moves == -1; i++)
        {
            int before1, before2, after1, after2;
            if (i != 0)
            {
                 before1 = a[i - 1];
                 before2 = a[i - 1] + 1;
            }
            if (i != n - 1)
            {
                 after1 = a[i + 2];
                 after2 = a[i + 2] + 1;
            }
            int l = min(a[i], a[i + 1]);
            int r = max(a[i], a[i + 1]);
            if (abs(a[i] - a[i + 1]) <= 1)
            {
                moves = 0;
                break;
            }
            else if (before1 >= l && before1 <= r && i != 0)
            {
                moves = 1;
                break;
            }
            else if (before2 >= l && before2 <= r && i != 0)
            {
                moves = 1;
                break;
            }
            else if (after1 >= l && after1 <= r && i != n-1)
            {
                moves = 1;
                break;
            }
            else if (after2 >= l && after2 <= r && i != n-1)
            {
                moves = 1;
                break;
            }
        }

        cout << moves << endl;
    }
    return 0;
}