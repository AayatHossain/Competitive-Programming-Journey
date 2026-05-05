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
        int a[n][n - 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<int> p;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i][0]]++;
        }
        vector<pair<int, int>> pairs;
        for (auto x : m)
        {
            pairs.push_back({x.second, x.first});
        }
        sort(pairs.rbegin(), pairs.rend());
        int large = pairs[0].second;
        int small = pairs[1].second;
        p.push_back(large);
        p.push_back(small);
        for (int j = 1; j < n-1; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] != small)
                {
                    p.push_back(a[i][j]);
                    small = a[i][j]; break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}