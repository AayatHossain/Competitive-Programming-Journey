#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int h, s;
        cin >> h >> s;
        a.push_back({s, h});
    }
    multiset<int> s;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    sort(a.rbegin(), a.rend());
    int c = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int v = a[i].second;

        auto it = s.lower_bound(v); 

        if (it != s.end())
        {
            cnt++;
            c += a[i].first;
            s.erase(it); 
        }
    }
    if(cnt < m)c = -1;
    cout << c << endl;
}