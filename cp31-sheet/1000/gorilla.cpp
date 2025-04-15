#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<int> b;
        for (auto x : m)
        {
            b.push_back(x.second);
        }
        sort(b.rbegin(), b.rend());
        int count = 0;
        int total = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (i == 0)
            {
                total += b[i] + k;
            }
            else
            {
                total += b[i];
            }
            count++;
            if (total >= n)
            {
                break;
            }
            if (count >= n)
            {
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}