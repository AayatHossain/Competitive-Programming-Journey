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
        int d = n%6;
        bool v1 = false,v2 = false;
        if(d==4 || d==5 || d == 0){
            v1 = true;
        }
        if(d==1 || d == 2 || d == 3){
            v2 = true;
        }
       
        if (v2)
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
    // cout<<ans<<endl;
    return 0;
}