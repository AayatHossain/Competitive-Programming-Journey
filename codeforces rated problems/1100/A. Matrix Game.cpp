#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int ca=0, cb = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    f = 0;
                }
            }
            if (f)
            {
                ca++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int f = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[j][i] == 1)
                {
                    f = 0;
                }
            }
            if (f)
            {
                cb++;
            }
        }
        int cnt = min(ca,cb);
        // cout<<cnt<<" "<<ca<<" "<<cb<<endl;
        if (cnt & 1)
        {
            cout << "Ashish" << "\n";
        }
        else
        {
            cout << "Vivek" << "\n";
        }
    }
    return 0;
}