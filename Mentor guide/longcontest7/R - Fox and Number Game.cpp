#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    int flag = 0;
    while (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            int c = 1;
            for(int i = 0; i < n-1; i++){
                if(a[i]==a[i+1]){
                    c++;
                }
            }
            if(c==n){
                flag = 1;
                break;
            }
            int v = a[i];
            int mn = LLONG_MAX / 2;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (v > a[j])
                {

                    if (v % a[j] == 0)
                    {
                        int q = v / a[j] - 1;
                        int nv = v - q * a[j];
                        mn = min(nv, mn);
                    }
                    else
                    {
                        mn = min(mn, v % a[j]);
                    }
                    // cout<<v<<" "<<a[j]<<" "<<mn<<endl;
                }
            }
            // cout<<mn<<endl;
            if (mn == LLONG_MAX / 2)
            {
                continue;
            }
            else
            {
                a[i] = mn;
            }
        }
    }

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }
    cout << s << endl;
    return 0;
}