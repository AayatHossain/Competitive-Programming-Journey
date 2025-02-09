#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, p;
        cin >> n >> p;
        long long a[n];
        long long b[n];
        for (long long i = 0; i < n; i++)
        {

            cin >> a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<pair<long long, long long>> c;
        for (long long i = 0; i < n; i++)
        {
            c.push_back(make_pair(b[i], a[i]));
        }
        sort(c.begin(), c.end());
        // for (long long i = 0; i < n; i++)
        // {
        //     cout << c[i].first << " ";
        // }
        // cout << endl;
        long long count = 0;
        long long countIndex = 0;
        for (long long i = 0; i < n; i++)
        {
            count++;
            countIndex++;
            count += c[i].second;
            long long left = n - count;
            if (left <= 0)
            {
                break;
            }
        }
        long long total = 0;
        total += countIndex * p;

        long long currentPeople = countIndex;
        // cout<<" total: "<<total<<endl;
        // cout<<" currpeople"<<currentPeople<<endl;
        // cout<<" count"<<count<<endl;

        for (long long i = 0; i < n; i++)
        {
            long long left = n - 1 - c[i].second;
            if (currentPeople >= n)
            {
                break;
                
            }else{
               currentPeople += c[i].second;
                long long required = c[i].second;
                total += required*c[i].first;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}