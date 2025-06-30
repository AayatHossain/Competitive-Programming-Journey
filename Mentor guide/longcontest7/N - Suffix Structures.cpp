#include <bits/stdc++.h>
using namespace std;
signed main()
{
    string s;
    string t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    if (n == m)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            cout << "array" << endl;
        }
        else
        {
            cout << "need tree" << endl;
        }
    }
    else if (n > m)
    {
        int f1 = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == m)
        {
            f1 = 1;
        }
       
        if (f1)
        {
            cout << "automaton" << endl;
        }
        else
        {
            int f2 = 0;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            int i = 0;
            int j = 0;
            while (i < n && j < m)
            {
                if (s[i] == t[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            if (j == m)
            {
                f2 = 1;
            }
            if (f2)
            {
                cout << "both" << endl;
            }else{
                cout << "need tree" << endl;

            }
        }
    }
    else
    {
        cout << "need tree" << endl;
    }
    return 0;
}