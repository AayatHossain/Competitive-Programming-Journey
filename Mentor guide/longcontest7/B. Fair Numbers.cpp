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
        set<int> s;

        while (1)
        {
            int f = 1;
            int nn = n;
            while (nn > 0)
            {
                int x = nn%10;
                if(x != 0 && n%x != 0){
                    f = 0;
                    break;
                }
                nn/=10;
            }
            if (f == 1)
            {
                break;
            }
             n++;
        }
        cout << n << endl;
    }
}