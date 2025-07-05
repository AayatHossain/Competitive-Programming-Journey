#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        int f = 1;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (l % i == 0)
            {
                ans.push_back(l);
                // cout<<l<<" ";
            }
            else
            {
                int num = l + (i - (l % i));
                if (num > r)
                {
                    f = 0;
                    break;
                }
                // cout<<num<<" ";
                ans.push_back(num);
            }
        }
        if (f)
        {
            cout << "YES" << endl;
            for (int x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}