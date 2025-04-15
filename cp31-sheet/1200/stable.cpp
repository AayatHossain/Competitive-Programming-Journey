#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> m;
    int count = 1;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) > x)
        {
            count++;
            int diff = abs(a[i] - a[i + 1]);
            m[((diff-1)/x)]++;

        }
    }
    // cout << count << endl;
    if (k != 0)
    {
        for (auto x : m)
        {
            int cF = x.first;
            int cS = x.second;
            // cout << cF << "-" << cS << endl;
            if (cF * cS <= k)
            {
                count -= cS;
                k -= cF * cS;
            }
            else
            {
                int required = k / cF;
                if (required > cS)
                {
                    count -= cS;
                    k -= cF * cS;
                }
                else
                {
                    count -= required;
                    k -= cF * required;
                }
            }
            if(k==0){
                break;
            }
        }
    }
    cout << count << endl;

    return 0;
}