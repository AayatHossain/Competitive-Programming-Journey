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
        vector<pair<int, int>> a;
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            a.push_back({l, r});
            s.insert({l, r});
        }
        for (int i = 0; i < a.size(); i++)
        {
            pair<int, int> curr = a[i];
            int l = curr.first;
            int r = curr.second;
            if(l==r){
                cout<<l<<" "<<r<<" "<<r<<endl;
            }
            for (int j = l; j <= r; j++)
            {
                int nr = j - 1;
                int nl = j + 1;
                pair<int, int> leftPair = {l, nr};
                pair<int, int> rightPair = {nl, r};
                if (nr < l)
                {
                    if (s.find(rightPair) != s.end())
                    {
                        cout << l << " " << r << " " << j << endl;
                        break;
                    }
                }
                else if (nl > r)
                {
                    if (s.find(leftPair) != s.end())
                    {
                        cout << l << " " << r << " " << j << endl;
                        break;
                    }
                }
                else
                {
                    if (s.find(leftPair) != s.end() && s.find(rightPair) != s.end())
                    {
                        cout << l << " " << r << " " << j << endl;
                        break;
                    }
                    
                }
            }
        }
        cout<<endl;
    }
    return 0;
}