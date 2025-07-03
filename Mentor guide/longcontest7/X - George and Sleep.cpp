#include <bits/stdc++.h>
using namespace std;
signed main()
{
    string s, t;
    cin >> s >> t;
    int v1 = s[0] - '0';
    int v2 = s[1] - '0';
    int v3 = s[3] - '0';
    int v4 = s[4] - '0';

    int h1 = v1 * 10 + v2;
    int m1 = v3 * 10 + v4;

    v1 = t[0] - '0';
    v2 = t[1] - '0';
    v3 = t[3] - '0';
    v4 = t[4] - '0';

    int h2 = v1 * 10 + v2;
    int m2 = v3 * 10 + v4;

    int m = 0, h = 0;
    int c = 0;
    if (m1 >= m2)
    {
        m = m1 - m2;
    }
    else
    {
        m = 60 - (m2 - m1);
        c++;
    }
    h2 += c;
    if (h1 >= h2)
    {
        h = h1 - h2;
    }
    else
    {
        h = 24 - (h2 - h1);
    }
    // cout << h << " " << m << endl;

    string ans;
    if (h < 10)
    {
        ans += '0';
        ans += to_string(h);
    }
    else
    {
        ans += to_string(h);
    }
    ans += ':';
    if (m < 10)
    {
        ans += '0';
        ans += to_string(m);
    }
    else
    {
        ans += to_string(m);
    }
    cout<<ans<<endl;
    // cout << h1 << " " << m1 << endl;
    return 0;
}