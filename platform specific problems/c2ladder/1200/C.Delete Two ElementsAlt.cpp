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
        vector<int> a(n);
        int s = 0;
        map<int,int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
            m[a[i]]++;
        }
        int f = 1;
        int ans = 0;

        double k = (double)s / n;
        double t = (double)2 * k;

        if((2*s)%n != 0){
            f = 0;
        }
        if(!f){
            cout<<0<<endl;
            continue;
        }

        for(int i = 0; i < n; i++){
            int v = t - a[i];
            ans += m[v];
            if(v==a[i])ans--;
        }

        cout << ans/2 << endl;
    }
    return 0;
}