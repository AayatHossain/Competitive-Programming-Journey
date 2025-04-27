#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int i = 0, j = 1;
        set<string> se;
        bool flag = 0;
        string last;
        string secondlast;
        while (j < n)
        {
            string subStr;
            subStr += s[i];
            subStr += s[j];
            if (j == n - 2)
            {
                secondlast = subStr;
            }
            if (j == n - 1)
            {
                last = subStr;
            }
            if (se.find(subStr) != se.end())
            {
                if (j == n - 1 && last == secondlast)
                {

                    j++;
                    i++;
                    continue;
                }
                else
                {
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
            else
            {
                se.insert(subStr);
            }
            i++;
            j++;
        }
        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
}