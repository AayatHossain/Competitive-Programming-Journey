#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+1;
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int p[N][32];
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            int m = 1LL << j;
            // cout<<i<<" "<<j<<endl;
            if (!(i & m))
            {
                p[i][j] = p[i-1][j] + 1;
            }else{
                p[i][j] = p[i-1][j];
            }
        }
    }

    int t;
    cin >> t;

    
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = INT_MAX;
        for (int i = 0; i < 32; i++)
        {
            int v = p[r][i] - p[l-1][i];
            ans = min(ans, v);
            if (v == 0)
            {
                ans = 0;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
