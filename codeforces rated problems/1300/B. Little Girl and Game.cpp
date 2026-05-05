#include <bits/stdc++.h>
using namespace std;
signed main()
{
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
    }
    int odd = 0;
    for (auto x : m)
    {
        if (x.second % 2)
            odd++;
    }

    if ((n % 2 == 0 && odd == 0) || (n % 2 == 1 && odd == 1))
    {
        cout << "First"<<endl;
    }
    else
    {
        if (n % 2 != 0)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
}