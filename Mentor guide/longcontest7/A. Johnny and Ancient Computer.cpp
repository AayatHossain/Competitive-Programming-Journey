#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int c)
{
    int a1 = c / 3;
    c = c % 3;
    int a2 = c / 2;
    c = c % 2;
    int a3 = c / 1;
    c = c % 1;
    return a1 + a2 + a3;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int c = 0;
        int ans = 0;
        if (a < b)
        {
            int i = 1;
            int v = a;
            while (v < b)
            {
                v = (a << i);
                c++;
                i++;
                // cout << v << endl;
            }
            if (v == b)
            {
                ans = f(c);
            }
            else
            {
                ans = -1;
            }
        }
        else
        {
            int i = 1;
            int v = a;
            while (v > b)
            {
                if(v&1){
                    break;
                }
                v = (a >> i);
                c++;
                i++;
                // cout << v << endl;
            }
            if (v == b)
            {
                ans = f(c);
            }
            else
            {
                ans = -1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}