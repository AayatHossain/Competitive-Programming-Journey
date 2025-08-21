#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, k;
        cin >> s >> k;
        int f = 1;
        int sum = 0;
        sum=k*k;
        // cout<<sum<<endl;
        if (sum > s)
        {
            f = 0;
        }
        else
        {
            if (k & 1)
            {
                if (s & 1)
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
                if (s & 1)
                {
                    f = 0;
                }
                else
                {
                    f = 1;
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}