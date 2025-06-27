#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (s.find(x) == s.end())
        {
            a.push_back(x);
            b.push_back(i + 1);
            s.insert(x);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int temp = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == x)
            {
                
                temp = b[i];
                for (int j = 0; j < a.size(); j++)
                {
                    if (b[j] < temp)
                    {
                        b[j]++;
                    }
                }
                cout<<temp<<" ";
                b[i] = 1;
                break;
            }
        }
    }
    return 0;
}