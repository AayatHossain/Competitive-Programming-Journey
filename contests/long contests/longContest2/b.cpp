#include <bits/stdc++.h>
using namespace std;
#define int long long

int lb(vector<int> &a, int n, int val)
{
    int l = -1, r = n;
    int mid;
    while (r > l + 1)
    {
        mid = l + (r - l) / 2;
        if (a[mid] < val)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int ub(vector<int> &a, int n, int val)
{
    int l = -1, r = n;
    int mid;
    while (r > l + 1)
    {
        mid = l + (r - l) / 2;
        if (a[mid] <= val)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c = 1;
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "Case " << c << ":" << endl;
        c++;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            int left = lb(a, n, l);
            int right = ub(a, n, r);
            if (right - left < 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << right - left + 1 << endl;
            }
        }
    }
    // cout<<endl;
    return 0;
}