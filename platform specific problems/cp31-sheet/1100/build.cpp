#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(vector<int> &a, int n)
{
    int amount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (n > a[i])
        {
            amount += (n - a[i]);
        }
    }
    return amount;
}

int bS(vector<int> a, int s, int e, int x)
{
    int m;
    int amount = -1;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        amount = calc(a, m);
        if (amount == x)
        {
            return m;
        }
        else if (amount > x)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return e;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int maxV = -1;

        for (int i = 0; i < n; i++)
        {

            maxV = max(maxV, a[i]);
        }

     

        int amount2 = calc(a, maxV);

        // cout<<amount1<<amount2<<endl;

        if (amount2 < x)
        {
            int perHeightIncrease = n;
            int diff = x - amount2;
            int steps = diff / perHeightIncrease;
            maxV += steps;
            cout << maxV << endl;
        }
        else
        {
            int s = 1;
            int e = maxV;
            int height = bS(a, s, e, x);
            cout<<height<<endl;
        }
    }
    return 0;
}