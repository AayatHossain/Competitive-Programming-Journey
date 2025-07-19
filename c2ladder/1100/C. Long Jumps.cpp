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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, int> m;
        int mx = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            int v;
            if (m.find(i) != m.end())
            {
                v = m[i] + a[i];
            }else{
                 v = a[i];
            }
            int index = i + a[i];
           
            if (m.find(index) != m.end())
            {
                if (v > m[index])
                {
                    m[index] = v;
                }
            }
            else
            {
                m[index] = v;
            }
            // m[index] = m[i] + a[i];
            mx = max(mx, m[index]);
        }
        cout << mx << endl;
    }
    return 0;
}