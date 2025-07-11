#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    string n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int n1, n2;
    n1 = 0;
    n2 = 0;
    int i;
    for (i = 0; i < n.size(); i++)
    {
        int v = n[i] - '0';
        n1 = n1 * 10 + v;
    }
    int z = 0;
    int m = 0;
    int j = n.size() - 1;
    cout<<n1<<endl;
    while (j >= 0)
    {
        int v = n[j] - '0';
        if (v == 0)
        {
            z++;
            j--;
            n1/=10;
        // cout << n1 << " " << n2 << endl;

            continue;
        }
        while (z > 0)
        {
            v *= 10;
            z--;
        }
        if (m != 0)
        {
            v *= m;
        }
        n2 = n2 + v;
        if (m == 0)
        {
            m = 10;
        }
        else
        {
            m *= 10;
        }

        n1 /= 10;
        if (n1 % a == 0 && n2 % b == 0)
        {
        cout << n1 << " " << n2 << endl;

            break;
        }
        j--;
        cout << n1 << " " << n2 << endl;
    }

    if (n1 == 0 || n2 == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << n1 << endl;
        cout << n2 << endl;
    }
    return 0;
}