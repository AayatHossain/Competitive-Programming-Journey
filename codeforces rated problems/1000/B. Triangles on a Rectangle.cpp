#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h;
        cin >> w >> h;
        int k;
        int ans = INT_MIN;
        for (int i = 0; i < 4; i++)
        {
            
            cin >> k;
            int mx = INT_MIN, mn = INT_MAX;
            for (int i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                mn = min(x, mn);
                mx = max(x, mx);
            }
            if(i==0 || i==1){
             ans = max(ans, (mx - mn) * h);
            }else{
                ans = max(ans, (mx - mn) * w);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}