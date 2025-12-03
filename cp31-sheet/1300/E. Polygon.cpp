#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char a[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int f = 1;
        for (int i = 1; i <= n && f && n > 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == n && j == n)
                {
                    continue;
                }

                if (a[i][j] == '1')
                {
                    if (i < n && j == n)
                    {
                        // char d = a[i + 1][j];

                        // if (!(d == '1'))
                        // {
                        //     f = 0;
                        //     cout<<f<<" "<<i<<" "<<j<<endl;

                        //     break;
                        // }
                        continue;
                    }
                    else if (i == n && j < n)
                    {
                        // char r = a[i][j + 1];
                        // if (!(r == '1'))
                        // {
                        //     f = 0;
                        //     break;
                        // }
                        continue;
                    }
                    else
                    {
                        char r = a[i][j + 1];
                        char d = a[i + 1][j];
                        if (!(r == '1' || d == '1'))
                        {
                            f = 0;
                            break;
                        }
                    }
                }
                
            }
            
        }
        
        if (f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}