#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        
            vector<int> ans(n, -1);
            int count = 1;
            for (int i = k - 1; i < n; i+=k)
            {
                
                    ans[i] = count;
                    count++;
                
            }
            count = n;
            for (int i = 0; i < n; i++)
            {
                if (ans[i] == -1)
                {
                    ans[i] = count;
                    count--;
                }
            }
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        
    }
    return 0;
}