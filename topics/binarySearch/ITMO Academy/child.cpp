#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ans;

int loons(int t, int z, int y, int tmid)
{

    int wt = z * t;
    int rt = y;
    int wpr = wt + rt;
    int interval = (tmid) / wpr;
    int rem = tmid - interval * wpr;
    int loons = interval * z;
    if (rem / t > z)
    {
        loons += z;
    }
    else
    {
        loons += rem / t;
    }
    return loons;
}

int isGood(vector<vector<int>> &a, int n, int m, int tmid)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];
        int bl = loons(t, z, y, tmid);
        total += bl;
    }
    return total >= m;
}

signed main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n, vector<int>(3));
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        int t, z, y;
        cin >> t >> z >> y;
        a[i][0] = t;
        a[i][1] = z;
        a[i][2] = y;
    }

    if (m == 0)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }
        return 0;
    }

    int l = 0, r = 1e7;
    int mid;
    while (r > l + 1)
    {
        mid = l + (r - l) / 2;
        if (isGood(a, n, m, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << endl;
    for (int i = 0; i < n; i++)
    {
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];
        ans[i] = loons(t, z, y, r);
    }

    int blown = 0;
    for (int i = 0; i < n; i++)
    {
        if (blown + ans[i] > m)
        {
            if(m-blown >= 0){
                cout<<m - blown<<" ";
            }else{
                cout<<"0 "<<endl;
            }
        }
        else
        {
            cout << ans[i] << " ";
        }
        blown += ans[i];
    }
    cout << endl;

    return 0;
}