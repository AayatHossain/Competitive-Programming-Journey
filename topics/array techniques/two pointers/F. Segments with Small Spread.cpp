#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int i = 0, j = 0;
    multiset<int> ms;
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ms.insert(a[i]);
        mn = *ms.begin();
        mx = *ms.rbegin();
        // cout<<mn<<" "<<mx<<endl;
        while (j < i && mx - mn > k)
        {
            auto it = ms.find(a[j]);
            ms.erase(it);
            j++;
            
            mn = *ms.begin();
            mx = *ms.rbegin();
            
        }
        ans += i - j + 1;
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}