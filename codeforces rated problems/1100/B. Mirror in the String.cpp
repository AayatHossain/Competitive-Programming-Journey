#include <bits/stdc++.h>>
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
        int i = 0;
        string ans;
        int f = 0;
        while (i + 1 < n && s[i] > s[i + 1])
        {

            // cout<<ans<<endl;
            i++;
            f = 1;
        }
        // cout<<i<<endl;
        if (i + 1 < n && s[i] >= s[i + 1] && f==1)
        {
           
            while (i < n && s[i-1] >= s[i])
            {
                // cout<<ans<<endl;
                i++;
            }
            i--;
        }
        // cout<<i<<endl;
        for (int j = 0; j <= i; j++)
        {
            ans += s[j];
        }
        for (int j = i; j >= 0; j--)
        {
            ans += s[j];
        }
        cout << ans << endl;
    }

    return 0;
}