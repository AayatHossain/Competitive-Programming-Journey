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
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int r = (px - qx) * (px - qx) + (py - qy) * (py - qy);
        int d = sqrt(r);
        int f;
        if (d == 0)
        {
            if (n == 1)
            {
                f = 0;
            }
            else if (n == 2)
            {
                int s = 0;
                
               if(a[0]==a[1])
                {
                    f = 1;
                }
                else
                {
                    f = 0;
                }
            }
            else
            {
                f = 1;
            }
        }
        else
        {
            int s = 0;
            for (int i = 0; i < n; i++)
            {

                s += a[i];
            }
            if (s >= d)
            {
                f = 1;
            }
            else
            {
                f = 0;
            }
        }
        if (f)
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