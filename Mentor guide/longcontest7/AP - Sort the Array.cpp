#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    int f = 1;
    // int c = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            l = i;
            // c++;
            while (i < n - 1 && a[i] > a[i + 1])
            {
                i++;
            }
            i--;
            r = i + 1;
            break;
        }
    }
    int i = l, j = r;
    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    if (a == b)
    {
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
    {
        cout << "no" << endl;
        // cout << -1 << endl;
    }

    return 0;
}