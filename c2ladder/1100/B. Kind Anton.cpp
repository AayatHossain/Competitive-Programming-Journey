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
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int f1 = 0, f2 = 0;
        int f = 1;
        if (a[0] != b[0])
        {
            f = 0;
        }
        else
        {

            if (a[0] > 0)
                f1 = 1;
            if (a[0] < 0)
                f2 = 1;

            for (int i = 1; i < n; i++)
            {

                if (a[i]<b[i])
                {
                    if(!f1){
                        f=0;
                        break;
                    }
                }
                else if (a[i]>b[i])
                {
                    if(!f2){
                        f=0;
                        break;
                    }
                }
                

                if (a[i] > 0)
                    f1 = 1;
                if (a[i] < 0)
                    f2 = 1;
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