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
        cout << pow(2, n) - 1 << " ";
        for (int i = 1; i <= n; i++)
        {
            int max2poweri = pow(2, i);
            for (int j = 0; j < max2poweri; j += 2)
            {
                int fixedBits = pow(2, n - i) - 1;
                int variableEvenBits = j*pow(2,n-i);
                int v = variableEvenBits + fixedBits;
                cout<<v<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}