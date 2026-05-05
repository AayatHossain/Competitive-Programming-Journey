#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> bits(32, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (auto x : a)
        {
            for (int i = 0; i < 32; i++)
            {
                int mask = (1 << i);
                if (x & mask)
                {
                    bits[i]++;
                }
            }
        }
        vector<int> ans = {1};
        for (int i = 2; i <= n; i++)
        {
            int f = 1;
            for (int j = 0; j < 32; j++)
            {
                if (bits[j] % i != 0)
                {
                    f = 0;
                    break;
                }
            }
            if (f)
                ans.push_back(i);
        }
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}