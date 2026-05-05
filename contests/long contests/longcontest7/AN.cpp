#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string s;
    cin >> s;
    // cout<<s<<endl;
    int n = s.size();
    int f = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int v = s[i] - '0';
        if (!(v & 1))
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        f = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int val = s[i] - '0';
            if (val % 2 == 0 && val < (s[n - 1] - '0'))
            {
                swap(s[i], s[n - 1]);
                f = 1;
                break;
            }
        }
        if (!f)
        {
            for (int i = n - 2; i >= 0; i--)
            {
                int val = s[i] - '0';
                if (val % 2 == 0)
                {
                    swap(s[i], s[n - 1]);
 
                    f = 1;
                    break;
                }
            }
        }
      
        cout << s << endl;
    }
     
    return 0;
}