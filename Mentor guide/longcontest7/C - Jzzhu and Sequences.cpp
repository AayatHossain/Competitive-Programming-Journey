#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
signed main()
{
    int x, y, n;
    cin >> x >> y;
    cin >> n;
    int ans;
    if (n == 1)
    {
        ans = x;
        
    }
    else if (n == 2)
    {
        ans = y;
        
    }
    else if (n == 3)
    {
        ans = y-x;
        
    }
    else
    {
       
        if ((n / 3) & 1)
        {
            if (n % 3 == 1)
            {
                ans = x;
            }
            else if (n % 3 == 2)
            {
                ans = y;
            }
            else
            {
                ans = (y - x);
            }
        }
        else
        {
            if (n % 3 == 1)
            {
                ans = -x;
            }
            else if (n % 3 == 2)
            {
                ans = -y;
            }
            else
            {
                ans = -(y - x);
            }
        }
        
        
    }
    cout << ((ans % mod) + mod) % mod << endl;
    return 0;
}