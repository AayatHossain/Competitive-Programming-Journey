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
        string s;
        cin >> s;
        int ca = 0, cb = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                ca++;
            else
                cb++;
        }
        char c;
        int extra;
        if (ca > cb)
        {
            c = 'a';
            extra = ca - cb;
        }
        else
        {
            c = 'b';
            extra = cb - ca;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n && extra > 0; i++)
        {
            int j = i + 1;
            char ch = s[i];
            int cnt = j - i + 1;

            while (j < n && s[i] == s[j])
            {
                cnt = j - i + 1;
                if (ch == c && cnt >= extra)
                {
                    ans = min(ans, cnt);
                }
                j++;
            }
            j--;
            cnt = j - i + 1;
            i = j;

            if (ch == c && cnt >= extra)
            {
                ans = min(ans, cnt);
            }
        }
        if (extra == 0)
            ans = 0;
        else if (ans == INT_MAX)
            ans = -1;
        else if (ans == n)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}