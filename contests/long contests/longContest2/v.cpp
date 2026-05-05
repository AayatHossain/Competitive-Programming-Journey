#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(vector<int> &a, int n, int m, int mid)
{
    int count = 1;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += a[i];
        if (curr > mid)
        {
            count++;
            if(count > m){
                return 0;
            }
            curr = a[i];
        }
    }
    return count <= m;
}
signed main()
{
    int t;
    cin >> t;
    int count = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // if(n <= m){
        //     m = n-1;
        // }
        vector<int> a(n);
        int maxV = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maxV = max(maxV, a[i]);
        }
        // if (n <= m)
        // {
        //     cout << "Case " << count << ": " << maxV << endl;
        //     count++;
        //     continue;
        // }
        int l = maxV-1, r = 1e9 + 7;
        int mid;
        while (r > l + 1)
        {
            mid = l + (r - l) / 2;
            if (ok(a, n, m, mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        cout << "Case " << count << ": " << r << endl;
        count++;
    }
}