#include <bits/stdc++.h>
using namespace std;
#define int long long
int findgcd(int a, int b)
{
    if (a == 0)
        return b;
    return findgcd(b % a, a);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int g = findgcd(a, b);
        int l = (a * b) / g;
        cout << l << " " << g << endl;
    }
    return 0;
}