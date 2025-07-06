#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int d;
    set<int> ds;
    for (int i = 1; i < n; i++)
    {
        ds.insert(a[i] - a[i - 1]);
        d = a[i] - a[i - 1];
    }

    vector<int> ans;
    if (n == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    else if (n == 2)
    {
        int m = (a[0] + a[1]) / 2;
        if (m - a[0] == a[1] - m)
        {
            ans.push_back(m);
        }

        ans.push_back(a[0] - d);

        ans.push_back(a[1] + d);
    }
    else
    {
        int sd = LLONG_MAX / 2;
        for (auto x : ds)
        {
            sd = min(sd, x);
        }
        if (ds.size() > 1)
        {

            int f = 1;
            for (int i = 1; i < n; i++)
            {
                if (a[i] - a[i - 1] != sd)
                {
                    int v = a[i - 1] + sd;
                    if (a[i] - v != sd)
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if (f)
            {
                int v;
                for (int i = 1; i < n; i++)
                {
                    if (a[i] - a[i - 1] != sd)
                    {
                        v = a[i - 1] + sd;

                        if (a[i] - v == sd)
                        {
                            break;
                        }
                    }
                }
                ans.push_back(v);
            }
        }
        else
        {
            ans.push_back(a[0] - d);
            ans.push_back(a[n - 1] + d);
        }
    }

    set<int> ans2;
    for(int i = 0; i < ans.size(); i++){
        ans2.insert(ans[i]);
    }
    // sort(ans.begin(), ans.end());
    cout << ans2.size() << endl;
    for (auto x : ans2)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}