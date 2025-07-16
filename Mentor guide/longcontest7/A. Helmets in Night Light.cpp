#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
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
        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = {b[i], a[i]};
        }
        sort(c.begin(), c.end());
        int left = n;
        int cost = 0;
        cost += p;
        left--;
        for (int i = 1; i < n; i++)
        {
            int q = c[i].first;
            int r = c[i].second;
            if (p < q)
            {
                cost += p;
                left--;
            }
            else
            {
                if (r > left)
                {
                    cost += left * q;
                    left = 0;
                    break;
                   
                }
                else
                {
                    cost += r * q;
                    left -= r;
                }
            }
            if(left == 0){
                break;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}