#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            int val = a[i];
            int canAdd = 1;
            for (int j = 0; j <= 31; j++)
            {
                int mask = (1 << j);
                if ((val & mask) && !(k & mask))
                {
                    canAdd = 0;
                    break;
                }
            }
            if (canAdd)
            {
                v |= val;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int val = b[i];
            int canAdd = 1;
            for (int j = 0; j <= 31; j++)
            {
                int mask = (1 << j);
                if ((val & mask) && !(k & mask))
                {
                    canAdd = 0;
                    break;
                }
            }
            if (canAdd)
            {
                v |= val;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int val = c[i];
            int canAdd = 1;
            for (int j = 0; j <= 31; j++)
            {
                int mask = (1 << j);
                if ((val & mask) && !(k & mask))
                {
                    canAdd = 0;
                    break;
                }
            }
            if (canAdd)
            {
                v |= val;
            }
            else
            {
                break;
            }
        }

        // cout<<v<<endl;
        if (v == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}