#include <bits/stdc++.h>
using namespace std;
#define int long long
int fn(vector<int> a, int n, int k, int t, int s)
{
    int ans = 0;
    if (t)
    {

        int i = 0;
        while (i < n && a[i] < 0)
        {
            a[i] = LLONG_MAX / 2;
            i++;
        }
        int c = 0;
        for (int i = s + 1; i < n; i++)
        {
            if (c < k)
            {
                c++;
            }
            if (c == k)
            {
                ans += abs(a[i]);
                c = 0;
            }
        }
        if (c > 0)
        {
            ans += abs(a[i - 1]);
        }

        i = s - 1;
        for (i = s - 1; i>=0 && a[i] != LLONG_MAX / 2 ; i--)
        {
            if (c < k)
            {
                c++;
            }
            if (c == k)
            {
                ans += abs(a[i]);
                c = 0;
            }
        }
        if (c > 0)
        {
            ans += abs(a[i + 1]);
        }
        ans += abs(a[0]);

    }
    else
    {
        int fv = a[0];
        int lv = a[n-1];
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
        int i = n-1;
        while (i >= 0 && a[i] > 0 && n-i<=k)
        {
            a[i] = 69;
            i--;
        }
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
        int c = 0;

        i = s - 1;
        for (i = s - 1; i >= 0; i--)
        {
            if (c < k)
            {
                c++;
            }
            if (c == k)
            {
                ans += 2*abs(a[i]);
                c = 0;
            }
        }
        
        if (c > 0)
        {
            ans += 2*abs(a[i + 1]);
        }

        i = s+1;
        for ( i = s + 1; i < n && a[i]!=69; i++)
        {
            if (c < k)
            {
                c++;
            }
            if (c == k)
            {
                ans += 2*abs(a[i]);
                c = 0;
            }
        }
        cout<<c<<" "<<i<<" "<<endl;
        if (c > 0)
        {
            ans += 2*abs(a[i - 1]);
        }
        ans += abs(lv);
        cout<<ans<<endl;

    }
    return ans;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        int f = 0;
        int s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x >= 0 && !f)
            {
                a.push_back(0);
                a.push_back(x);
                f = 1;
                s = i;
            }else{
                a.push_back(x);
            }
        }
        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        n++;
        int v1 = fn(a, n, k, 0, s);
        int v2 = fn(a, n, k, 1, s);
        cout << min(v1, v2) << endl;
    }
    return 0;
}