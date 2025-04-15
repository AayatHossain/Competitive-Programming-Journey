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
        cin >> n;
        priority_queue<int> pq;
        int ans = 0;
        // int curr = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                int val = 0;
                if (!pq.empty())
                {
                    val = pq.top();
                    pq.pop();

                }
                ans += val;
            }
            else
            {
                pq.push(x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}