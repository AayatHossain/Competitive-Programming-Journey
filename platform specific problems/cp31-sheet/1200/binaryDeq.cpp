#include <bits/stdc++.h>
using namespace std;

int query(int l, int r, vector<int> &pref){
    int sum = pref[r] - (l ? pref[l-1] : 0);
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        vector<int> pref(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pref[i] = a[i];
            if(i){
                pref[i] = pref[i] + pref[i-1];
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int l = i, r = n-1;
            int mid; int pos = -1;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                int sum = query( i,  mid, pref);
                if (sum <= s)
                {
                    pos = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            if(pos==-1 || query(i, pos, pref) != s){
                continue;
            }else{
                ans = min(ans, n - (pos - i + 1));
            }
        }
        if(ans == INT_MAX){
            ans = -1;
        }
        cout << ans << endl;
    }

    return 0;
}