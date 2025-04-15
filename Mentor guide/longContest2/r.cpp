#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;

        sort(a.begin(), a.end());
        int first = -1, second = -1;
        for (int i = 0; i < n - 1; i++)
        {
            int req = m - a[i];

            int l = i + 1, r = n - 1;
            int mid;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                if (a[mid] == req)
                {
                    first = a[i];
                    second = a[mid];
                    break;
                }
                else if (a[mid] < req)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << first << " and " << second <<"."<< endl;
        cout<<endl;

        // cin.ignore(); 
        // cin.ignore();
    }

    return 0;
}