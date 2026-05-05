#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        int count = 0;
        int countLeft = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                count++;
                if (i < n - 2)
                {
                    countLeft++;
                }
            }
        }
        if (count == n)
        {
            cout << 0 << endl;
            continue;
        }else if(count==0){
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
            continue;
        }

        char prev = s[n - 2];
        char next = s[n - 1];
        if (prev == c && next != c)
        {
            cout << 1 << endl;
            cout << n - 1 << endl;
        }
        else if (prev != c && next == c)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else if ((prev != c && next != c) && count ==n-2)
        {
            int notDiv = -1;
            for (int i = n - 2; i >= 1; i--)
            {
                if ((n % i != 0) && ((n - 1) % i != 0))
                {
                    notDiv = i ;
                    break;
                }
            }
            if (notDiv == -1)
            {
                cout << 2 << endl;
                cout << n - 1 <<" "<< n << endl;
            }
            else
            {
                cout << 1 << endl;
                cout << notDiv << endl;
            }
        }
        else if((prev != c && next != c) && count < n-2){
            cout << 2 << endl;
            cout << n - 1 <<" "<< n << endl;
        }
        else
        {
            cout << 1 << endl;
            cout << n - 1 << endl;
        }
    }

    return 0;
}