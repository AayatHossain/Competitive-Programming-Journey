#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x: b){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int f = 1;
        if (n <= m)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] <= b[i])
                {
                    f = 0;
                    // cout<<a[i]<<" "<<b[i]<<endl;
                    break;
                }
            }
        }
        else
        {
            f = 0;
        }
        if (f)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}