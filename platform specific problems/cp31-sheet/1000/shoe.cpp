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
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            m[x]++;
        }
        int dup = 1;
        for (auto x : m)
        {
            if (x.second == 1)
            {
                dup = 0;
            }
        }
        // cout << distinct << " " << dup << endl;
        if (m.size() == 1)
        {
            int count = 0;
            for (auto x : m)
            {
                count = x.second;
            }
            if (count == 1)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << n << " ";
                for (int i = 1; i < n; i++)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
        else if (dup)
        {
            vector<int> ans;

            int before = 0;

            for (auto x : m)
            {
                int amount = x.second;

                if (amount % 2 == 0)
                {
                    int after = before + amount;
                    int amounttemp = amount;
                    int aftertemp = after;
                    while (aftertemp > before)
                    {
                        ans.push_back(aftertemp);
                        aftertemp--;
                        amounttemp--;
                    }
                }
                else
                {
                    int last = before + amount;
                    ans.push_back(last);
                    last--;
                    for (int i = before + 1; i <= last; i++)
                    {
                        ans.push_back(i);
                    }
                }

                before = before + amount;
            }
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}