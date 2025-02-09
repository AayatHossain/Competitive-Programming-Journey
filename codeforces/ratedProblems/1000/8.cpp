#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        if (n == 1)
        {
            if (m == 2)
            {
                if (a[0][1] < a[0][0])
                {
                    a[0][0] = a[0][1];
                }
                if(a[0][1] > a[0][0]){
                    a[0][1] = a[0][0];
                }
            }
            else
            {
                if (a[0][1] < a[0][0])
                {
                    a[0][0] = a[0][1];
                }
                for (int i = 1; i < m-1; i++)
                {
                    if (a[0][i] > a[0][i - 1] && a[0][i] > a[0][i+1])
                    {
                        a[0][i] = max(a[0][i-1],a[0][i+1]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout << i << " " << j << endl;
                if (i == 0)
                {
                    if (j == 0)
                    {
                        if (a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j])
                        {
                            int maxVal = max(a[i][j + 1], a[i + 1][j]);
                            a[i][j] = maxVal;
                            continue;
                        }
                        else
                        {
                            continue;
                            ;
                        }
                    }
                    if (j == m - 1)
                    {
                        if (a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j])
                        {
                            int maxVal = max(a[i][j - 1], a[i + 1][j]);
                            a[i][j] = maxVal;
                            continue;
                        }
                        else
                        {
                            continue;
                            ;
                        }
                    }
                    if ((a[i][j] > a[i][j + 1]) && (a[i][j] > a[i + 1][j]) && (a[i][j] > a[i][j - 1]))
                    {
                        int maxVal = max(a[i][j + 1], max(a[i][j - 1], a[i + 1][j]));

                        a[i][j] = maxVal;
                        continue;
                    }
                    else
                    {

                        continue;
                    }
                }

                if (i == n - 1)
                {
                    if (j == 0)
                    {
                        if (a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j])
                        {
                            int maxVal = max(a[i][j + 1], a[i - 1][j]);
                            a[i][j] = maxVal;
                            continue;
                        }
                        else
                        {
                            continue;
                            ;
                        }
                    }
                    if (j == m - 1)
                    {
                        if (a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j])
                        {
                            int maxVal = max(a[i][j - 1], a[i - 1][j]);
                            a[i][j] = maxVal;
                            continue;
                        }
                        else
                        {
                            continue;
                            ;
                        }
                    }
                    if (a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1])
                    {
                        int maxVal = max(a[i][j + 1], max(a[i][j - 1], a[i - 1][j]));
                        a[i][j] = maxVal;
                        continue;
                    }
                    else
                    {
                        continue;
                        ;
                    }
                }
                // i > 0 and < n

                if (j == 0)
                {
                    if (a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j])
                    {
                        int maxVal = max(a[i][j + 1], max(a[i + 1][j], a[i - 1][j]));
                        a[i][j] = maxVal;
                        continue;
                    }
                    else
                    {
                        continue;
                        ;
                    }
                }
                if (j == m - 1)
                {
                    if (a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j])
                    {
                        int maxVal = max(a[i][j - 1], max(a[i + 1][j], a[i - 1][j]));
                        a[i][j] = maxVal;
                        continue;
                    }
                    else
                    {
                        continue;
                        ;
                    }
                }
                // other cases

                if (a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1])
                {

                    int maxVal = max(max(a[i][j + 1], a[i][j - 1]), max(a[i + 1][j], a[i - 1][j]));
                    a[i][j] = maxVal;
                    continue;
                }
                else
                {
                    continue;
                    ;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
