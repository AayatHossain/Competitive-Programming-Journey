#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, m;
    cin >> n >> m;
    int b[n][m];
    int a[n][m];
    memset(a, -1, sizeof a);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    a[i][k] = 0;
                }
                for (int k = 0; k < n; k++)
                {
                    a[k][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == -1)
            {
                a[i][j] = 1;
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = 0;
            for (int k = 0; k < m; k++)
            {
                val = val | a[i][k];
            }
            for (int k = 0; k < n; k++)
            {
                val = val | a[k][j];
            }
            if (val != b[i][j])
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}