#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        int v1 = abs(x - a);
        int v2 = abs(y - a);
        int flag = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (i != a)
            {
                int v3 = abs(x - i);
                int v4 = abs(y - i);
                
                if ((v3 < v1 && v4 < v2) || (v3 < v2 && v4 < v1))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
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