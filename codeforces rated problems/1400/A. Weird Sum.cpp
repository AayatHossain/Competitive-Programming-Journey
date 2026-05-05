#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> x(1e5);
vector<vector<int>> y(1e5);

int f(vector<int> &a)
{
    sort(a.rbegin(), a.rend());
    int k = a.size();
    int v = k - 1;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += v * a[i];
        v -= 2;
    }
    return ans;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            x[a[i][j]].push_back(i);
            y[a[i][j]].push_back(j);
        }
    }
    int ans = 0;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i].size() == 0)
            continue;

        ans += f(x[i]);
        ans += f(y[i]);
    }
    cout << ans << endl;
    return 0;
}