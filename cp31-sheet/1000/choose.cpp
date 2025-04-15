#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n);
        vector<long long> b(m);
        set<long long> sa, sb;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= k)
            {
                sa.insert(a[i]);
            }
        }
        for (long long i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] <= k)
            {
                sb.insert(b[i]);
            }
        }
        map<long long, pair<long long, long long>> count;
        for (long long i = 0; i < n; i++)
        {
            if (a[i] <= k)
            {
                long long val = a[i];
                pair<long long, long long> p = make_pair(1, 1);
                count[val] = p;
            }
        }

       

        for (long long i = 0; i < m; i++)
        {
            long long val = b[i];
            if (val <= k)
            {
                if (sa.find(val) != sa.end())
                {
                    pair<long long, long long> p = make_pair(2, -1);
                    count[val] = p;
              
                    continue;
                }
                else
                {
                    pair<long long, long long> p = make_pair(1, 2);
                    count[val] = p;
                }
            }
        }
        long long x1 = 0, x2 = 0;
        for (auto x : count)
        {
            if (x.second.first == 1)
            {
                long long from = x.second.second;
                if (from == 1)
                {
                    x1++;
                }
                else if (from == 2)
                {
                    x2++;
                }
            }
        }
        long long mV = k / 2;
        if (x1 == k / 2 && x2 == k / 2)
        {
            cout << "YES" << endl;
        }
        else if (x1 > k / 2 || x2 > k / 2)
        {
            cout << "NO" << endl;
        }
        else if(count.size() == k)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

        // for (auto x : sa)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : sb)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << dup << endl;
        // cout << x1 << " " << x2 << endl;
        // for (auto x : count)
        // {
        //     cout << x.first << " " << x.second.first << endl;
        // }
    }
    return 0;
}