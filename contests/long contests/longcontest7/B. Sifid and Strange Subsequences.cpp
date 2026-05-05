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
        vector<int> a(n);
        vector<int> ans;
        int sp = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
            {
                sp = min(sp, a[i]);
            }
            if (a[i] <= 0)
            {
                ans.push_back(a[i]);
            }
        }
        if (sp == INT_MAX)
        {
            cout << ans.size() << endl;
        }
        else
        {
            if (ans.size() > 1 && sp != INT_MAX)
            {
                sort(ans.begin(), ans.end());
                int f = 1;
                for (int i = 0; i < ans.size() - 1; i++)
                {
                    if (abs(ans[i] - ans[i + 1]) < sp)
                    {
                        // cout<<i<<endl;
                        f = 0;
                        break;
                    }
                }
                if (f)
                {
                    cout << ans.size() + 1 << endl;
                }
                else
                {
                    cout << ans.size() << endl;
                }
            }else if(ans.size()==1 && sp != INT_MAX){
                cout<<2<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }
    return 0;
}