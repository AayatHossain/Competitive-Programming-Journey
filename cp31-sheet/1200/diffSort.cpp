#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        };
        vector<long long> b = a;
        sort(b.begin(), b.end());

        if (b == a)
        {
            cout << "0" << endl;
            continue;
        }

        if (a[n - 2] > a[n - 1])
        {
            cout << -1 << endl;
        }
        else
        {
            long long prev = n - 2;
            long long next = n - 1;
            long long valid = (a[prev] <= 0 && a[next] >= 0) || (a[prev] >= 0 && a[next] >= 0) ;
            if (valid)
            {
                vector<pair<pair<long long, long long>, long long>> ans;
                long long curr = a[n - 1];
                long long prevCurr = a[n-2];
                long long y = n-1;
                long long z = n;
                for (long long i = n - 3; i >= 0; i--)
                {
                    a[i] = prevCurr - curr;
                    long long x = i + 1;
                    
                    pair p1 = make_pair(x, y);
                    pair p2 = make_pair(p1, z);
                    ans.push_back(p2);
                }

                cout << ans.size() << endl;
                for (long long i = 0; i < ans.size(); i++)
                {
                    long long x = ans[i].first.first;
                    long long y = ans[i].first.second;
                    long long z = ans[i].second;
                    cout << x << " " << y << " " << z << endl;
                }
                // for(long long i = 0; i < n; i++){
                //     cout<<a[i]<<" ";
                // }
            }else{
                cout<<-1<<endl;
            }

            
        }
    }
    return 0;
}