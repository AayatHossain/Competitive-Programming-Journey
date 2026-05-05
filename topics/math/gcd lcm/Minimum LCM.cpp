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

        int l = INT_MAX;
        int a;
        int b;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int v = lcm(i, n-i);
            
                if (v < l)
                {
                    l = v;
                    a = i;
                    b = n - i;
                }
                if(i==1){
                    continue;
                }
                v = lcm(n/i, n- n/i);
                
                if (v < l)
                {
                    l = v;
                    a = n/i;
                    b = n - n/i;
                }
            }
        }
        cout << a << " " << b << endl;
    }
}
