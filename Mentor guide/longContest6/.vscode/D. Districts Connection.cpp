#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = {x, i + 1};
            s.insert(x);
        }
        if (s.size() == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

        sort(a.begin(), a.end());
        // for(auto x: a){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<"-----------"<<endl;

        int i = 0, j = n - 1;
        int c = 1;
        while (i < j)
        {
            if (a[i].first == a[j].first)
            {
                break;
            }
            cout << a[i].second << " " << a[j].second << endl;

            if (c & 1)
            {
                i++;
            }
            else
            {
                j--;
            }
            c++;
        }
        // cout<<i<<" "<<j<<" "<<c<<endl;
        if (i < n - 1)
        {
            if (c % 2 != 0)
            {
                i++;
                j++;
            }
            // cout<<i<<" "<<j<<" "<<c<<endl;

            if (a[i].first != a[n - 1].first)
            {

                while (i < j)
                {
                    cout << a[i].second << " " << a[n - 1].second << endl;

                    i++;
                }
            }
            else if (a[i].first != a[0].first)
            {

                while (i < j)
                {
                    cout << a[i].second << " " << a[0].second << endl;

                    i++;
                }
            }
        }

        
    }
    return 0;
}