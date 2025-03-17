#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string l, r;
        cin >> l >> r;
        cout << l << " " << r << endl;
        int ans = 0;
        if(l==r){
            cout<<0<<endl; continue;
        }
        if (l.size() == r.size())
        {
            int smol = (int)l[0];
            int lorge = (int)r[0];
            if (smol < lorge)
            {
                ans += abs(smol - lorge);
                if (l.size() - 1 > 0)
                {
                    ans += (l.size() - 1) * 9;
                }
            }
            else
            {
                int indx = -1;
                for (int i = 0; i < l.size(); i++)
                {
                    if (l[i] < r[i])
                    {
                        int smol = (int)l[i];
                        int lorge = (int)r[i];
                        ans += abs(smol - lorge);
                        indx = i + 1;
                        break;
                    }
                }

                // for (int i = 0; i < l.size(); i++)
                // {
                //     int smol = (int)l[i];
                //     int lorge = (int)r[i];
                //     ans += abs(smol - lorge);
                // }
                
                ans += (r.size() - indx) * 9;
            }
        }
        else
        {
            ans += int(r[0] - '0');
            // cout<<ans<<endl;
            ans += (r.size() - 1) * 9;
        }
        cout << ans << endl;
    }
    return 0;
}