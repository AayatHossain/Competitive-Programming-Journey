#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a % 2 && b % 2)
        {
            if (a == 1)
            {
                cout << b * b << endl;
            }
            else
            {
                cout << a * b << endl;
            }
        }else{
            cout<<b*2<<endl;
        }
    }

    return 0;
}