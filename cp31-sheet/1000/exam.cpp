#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        set<int> ques, knows, dontknow;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            ques.insert(x);
        }
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            knows.insert(x);
        }
        for (int i = 1; i <= n; i++)
        {
            if (knows.find(i) == knows.end())
            {
                dontknow.insert(i);
            }
        }

        string s;
        int x = dontknow.size();
        if (x >= 2)
        {
            for (int i = 0; i < m; i++)
            {
                s += '0';
            }
        }
        else
        {
            if (x == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    s += '1';
                }
            }
            else
            {
                for (auto y : ques)
                {
                    if (knows.find(y) == knows.end())
                    {
                        s += '1';
                    }
                    else
                    {
                        s += '0';
                    }
                }
            }
        }

        cout << s << endl;
    }
    return 0;
}