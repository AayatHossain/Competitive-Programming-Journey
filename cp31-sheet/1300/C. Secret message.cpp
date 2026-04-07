#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];

        vector<vector<int>> b(n, vector<int>(26, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[j][a[i][j] - 'a'] = 1;
            }
        }

        string ans;
        set<int> s;
        for (int d = 1; d * d <= n; d++)
        {
            if (n % d)
                continue;
            s.insert(d);
            int d2 = n / d;
            if(d2==d)continue;
            s.insert(d2);
        }

        for (auto d : s)
        {
            string t;
            bool ok = true;

            for (int j = 0; j < d; j++)
            {
                bool found = false;
                for (int c = 0; c < 26; c++)
                {
                    bool good = true;
                    for (int pos = j; pos < n; pos += d)
                    {
                        if (!b[pos][c])
                        {
                            good = false;
                            break;
                        }
                    }
                    if (good)
                    {
                        t.push_back(char('a' + c));
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                ans.clear();
                for (int i = 0; i < n / d; i++)
                    ans += t;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}