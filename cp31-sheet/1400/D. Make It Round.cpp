#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int oldn = n;
        int c2 = 0, c5 = 0;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                c2++;
                n /= 2;
            }
            else
            {
                break;
            }
        }
        while (n > 0)
        {
            if (n % 5 == 0)
            {
                c5++;
                n /= 5;
            }
            else
            {
                break;
            }
        }

        int mn = min(c2, c5);
        c2 -= mn;
        c5 -= mn;
        int curr = 1;

        // for (int i = 0; i < mn; i++)
        // {
        //     curr *= 10;
        // }

        // cout<<c2<<" "<<c5<<endl;
        // cout<<curr<<endl;

        while (curr * 5 <= m && c2 > 0)
        {
            curr *= 5;
            c2--;
        }

        while (curr * 2 <= m && c5 > 0)
        {
            curr *= 2;
            c5--;
        }

        while (curr * 10 <= m)
        {
            curr *= 10;
        }
        curr *= (m / curr);
        // cout<<curr<<endl;
        cout << curr * oldn << endl;
    }
    return 0;
}