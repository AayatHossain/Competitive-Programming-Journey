#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
            {
                odd.push_back(a[i]);
            }
            else
            {
                even.push_back(a[i]);
            }
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        int os = odd.size();
        int es = even.size();
        int i = 0, j = 0;
        bool c = false;
        int s1 = 0, s2 = 0;
        // cout<<es<<" "<<os<<endl;
        while (i < es && j < os)
        {
            if (!c)
            {
                if (odd[j] <= even[i])
                {
                    s1 += even[i];
                    i++;
                }
                else
                {
                    // s1 += odd[j];
                    j++;
                }
                c = true;
            }
            else
            {
                if (odd[j] >= even[i])
                {
                    s2 += odd[j];
                    j++;
                }
                else
                {
                    // s2 += even[i];
                    i++;
                }
                c = false;
            }
            // cout << i << " " << j <<" "<<s1<<s2<<c<<endl;
            // if (c==0)
            // {
            //     c = 1;
            // }
            // else
            // {
            //     c = 0;
            // }
            // cout<<c<<endl;
        }
        // cout << i << " " << j << endl;
        if (i < es && j == os)
        {
            while (i < es)
            {
                if (!c)
                {
                    s1 += even[i];
                }
                i++;
                if (c)
                {
                    c = 0;
                }
                else
                {
                    c = 1;
                }
            }
        }
        if (i == es && j < os)
        {
            while (j < os)
            {
                if (c)
                {
                    s2 += odd[j];
                }

                j++;
                if (c)
                {
                    c = 0;
                }
                else
                {
                    c = 1;
                }
            }
        }
        // cout << s1 << " " << s2 << endl;
        if (s1 > s2)
        {
            cout << "Alice" << endl;
        }
        else if (s2 > s1)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Tie" << endl;
        }
    }
    return 0;
}