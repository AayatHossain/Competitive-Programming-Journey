#include <bits/stdc++.h>
using namespace std;
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
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(b.begin(), b.end());

        int mx = 1e9 + 7;
        mx = mx + a[n - 1];
        int index = upper_bound(b.begin(), b.end(), mx) - b.begin();
        index--;
        int v1 = b[index] - a[n-1];
        int mx2 = max(v1, a[n-1]);
        
        a[n-1] = mx2;
            
        

        for (int i = n - 2; i >= 0; i--)
        {
            int x = a[i] + a[i + 1];
            int index = upper_bound(b.begin(), b.end(), x) - b.begin();
            index--;

            if (a[i] > a[i + 1])
            {
                if (index < m && index >= 0)
                {
                    a[i] = b[index] - a[i];
                }
            }
            else
            {
                int v1 = b[index] - a[i];
                if(v1 > a[i+1]){
                    continue;
                }
                int mx = max(v1, a[i]);
                a[i] = mx;
            }
        }
        // for(auto x: a)cout<<x<<" ";
        // cout<<endl;
        int f = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                f = 0;
                break;
            }
        }
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}