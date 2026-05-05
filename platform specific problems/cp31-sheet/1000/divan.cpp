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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            int vis;
            cin >> vis;
            a[i] = make_pair(vis, i);
        }
        sort(a.rbegin(), a.rend());
        vector<pair<int, pair<int, int>>> b(n);
        int mid = 0;

        int right = 1;
        int left = -1;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = a[i];
            int vis = a[i].first;
            int index = a[i].second;
            if (i % 2 == 0)
            {

                b[i] = make_pair(index, make_pair(vis, right));
                right++;
            }
            else
            {
                b[i] = make_pair(index, make_pair(vis, left));
                left--;
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            pair<int, pair<int, int>> p = b[i];
            int vis = p.second.first;
            int cord = p.second.second;
            total += 2 * (abs(mid - cord)) * vis;
        }
        sort(b.begin(), b.end());
        cout << total << endl;
        cout << mid << " ";
        for (int i = 0; i < n; i++)
        {
            pair<int, pair<int, int>> p = b[i];
            int cord = p.second.second;
            cout << cord << " ";
        }
        cout << endl;
    }
    return 0;
}