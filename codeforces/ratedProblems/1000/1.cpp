// https://codeforces.com/problemset/problem/2005/B1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m, q;
        cin >> n >> m >> q;
        long long t1, t2;
        cin >> t1 >> t2;
        long long david;
        cin >> david;
        long long moves = 0;
        long long dist = 0;
        if(t1 > t2){
            long long temp = t1;
            t1 = t2;
            t2 = temp;
        }
        if (david > t1 && david < t2)
        {
            moves = (t2 - t1)/2;
          
        }
        else if (david > t2)
        {
            moves = n - t2;
        }
        else
        {
            moves = t1 - 1;
        }
        cout << moves << endl;
    }
    return 0;
}
