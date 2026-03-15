#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
         int c = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (k == n)
        {
            c = m / a[p];
            cout << c << endl;
            continue;
        }
        

        vector<int> b;
        b.push_back(0);
        for (int i = 1; i < p; i++)
        {
            b.push_back(a[i]);
        }
        for (int i = p + 1; i <= n; i++)
        {
            b.push_back(a[i]);
        }
        b.push_back(a[p]);
        if (m - a[p] < 0)
        {
            // cout<<"ho";
            cout << 0 << endl;
            continue;
            ;
        }
        a = b;
        m-=a[p];
        c++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<pair<int, int>> q;
        for (int i = 1; i <= k; i++)
        {
            // cout<<a[i]<<endl;
            pq.push({a[i], i});
        }
        for (int i = k + 1; i <= n; i++)
        {
            q.push({a[i], i});
        }
       
        //   for(auto x: a){
        //     cout<<x<<" ";
        //   }
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<endl;
        while (m > 0 && k < n)
        {
            pair<int, int> p1 = pq.top();
            pair<int, int> p2 = q.front();

            m -= p1.first;
            // cout<<pq.top().first<<endl;
            pq.pop();
            if (m < 0)
                break;
            q.push(p1);
            if (p2.second != p)
            {
                q.pop();
                pq.push(p2);
            }
            else
            {
                m -= p2.first;
                if (m < 0)
                    break;
                c++;
                q.pop();
                q.push(p2);
            }
        }
        if (k == n)
        {
            c = m / a[p];
        }
        cout << c << endl;
    }
    return 0;
}