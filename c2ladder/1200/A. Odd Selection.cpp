#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        int f = 1;
        if (x & 1)
        {
            if (odd == 0)
            {
                f = 0;
            }
            else
            {
                int c = 0;
                c++;
                odd--;
                c += even;
                if (c < x)
                {
                    int on = x - c;
                    if (on <= odd && on % 2 == 0)
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
        }
        else
        {
            if (even == 0 || odd == 0)
            {
                f = 0;
            }
            else
            {
                int c = 0;
                c++;
                odd--;
                c++;
                even--;
                c += even;
                if (c < x)
                {
                    int on = x - c;
                    if (on <= odd && on % 2 == 0)
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
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}