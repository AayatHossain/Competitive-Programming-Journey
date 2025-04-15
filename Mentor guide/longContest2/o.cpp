#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(string a, int n, int mid, int k)
{

    if (mid == 1)
    {
        int flips_start1 = 0; // Pattern: 1 0 1 0 ...
        int flips_start0 = 0; // Pattern: 0 1 0 1 ...
        for (int i = 0; i < a.size(); ++i)
        {
            char expected1 = (i % 2 == 0) ? '1' : '0';
            char expected0 = (i % 2 == 0) ? '0' : '1';
            flips_start1 += (a[i] != expected1);
            flips_start0 += (a[i] != expected0);
        }
        return min(flips_start1, flips_start0) <= k;
    }

    int flips = 0;
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[i] == a[j])
        {
            j++;
        }
        else
        {
            int count = j - i;
            flips += count / (mid + 1);
            // cout<<flips<<endl;
            i = j;
            j++;
        }
    }
    if (j - i > 1)
    {
        int count = j - i;
        flips += count / (mid + 1);
    }
    // cout<<flips<<endl;
    return flips <= k;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        // int m = ok(s,n,k);
        int l = 0, r = n;
        int mid;
        while (r > l + 1)
        {
            mid = l + (r - l) / 2;
            if (ok(s, n, mid, k))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}