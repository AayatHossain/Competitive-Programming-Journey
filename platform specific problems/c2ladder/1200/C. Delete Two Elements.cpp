#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        int f = 1;
        int ans = 0;
        int t;

        double kp = (double)s / n;
        double tp = (double)2 * kp;
        
        if (tp == floor(tp))
        {
            t = tp;
        }
        else
        {
            f = 0;
        }

        // cout<<kp<<" "<<tp<<" "<<tphalf+tphalf<<endl;
        if (!f)
        {
            cout << 0 << endl;
            continue;
        }
        // cout<<t<<endl;
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] <= t)
            {
                int n1 = a[i];
                int n2 = t - n1;
              
                int i1 = lower_bound(a.begin() + i + 1, a.end(), n2) - a.begin();
                int i2 = upper_bound(a.begin() + i + 1, a.end(), n2) - a.begin();
                
                ans += i2 - i1;

            }
        }
        cout << ans << endl;
    }
    return 0;
}