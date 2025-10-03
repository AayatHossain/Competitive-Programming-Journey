#include <bits/stdc++.h>
using namespace std;
#define int long long
void print(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void print(vector<vector<int>> &a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print(set<int> &a)
{
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}
void print(map<int, int> &a)
{
    for (auto x : a)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}

bool func1(string s, int n)
{
    if (n >= 5)
    {
        for (int i = 2; i < n - 2; i++)
        {
            string t;
            t += s[i - 2];
            t += s[i - 1];
            t += s[i];
            t += s[i + 1];
            t += s[i + 2];
            if (t == "11011")
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}

bool func2(string s, int n)
{
    if (n >= 4)
    {
        string t;
        t += s[0];
        t += s[1];
        t += s[2];
        t += s[3];
        if (t == "1011")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

bool func3(string s, int n)
{
    if (n >= 4)
    {
        string t;
        t += s[n - 4];
        t += s[n - 3];
        t += s[n - 2];
        t += s[n - 1];
        if (t == "1101")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

bool func4(string s, int n)
{
    if (n >= 8)
    {
        for (int i = 0; i <= n - 8; i++)
        {
            if (s.substr(i, 8) == "10101011")
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, ki, kj, di, dj;
        cin >> n >> ki >> kj >> di >> dj;

        int ans = -1;
        if (ki == di - 1 && kj == dj)
        {
            ans = di;
        }
        else if (ki == di && kj == dj - 1)
        {
            ans = dj;
        }
        else if (ki == di + 1 && kj == dj)
        {
            ans = n - di;
        }
        else if (ki == di && kj == dj + 1)
        {
            ans = n - dj;
        }


        if(ans == -1 && kj==dj){
            if(ki < di){
                ans = max(di,min(di-ki, n-dj));
            }else{
                ans = max(n-di,min(ki-di, dj));
            }
        }


        if(ans == -1 && ki==di){
            if(kj < dj){
                ans = max(dj,min(dj-kj, n-di));
            }else{
                ans = max(n-dj,min(kj-dj, di));
            }
        }





        int tl = ki < di && kj < dj;
        int tr = ki < di && kj > dj;
        int bl = ki > di && kj < dj;
        int br = ki > di && kj > dj;

        if (ans == -1)
        {
            if (tl )
            {
                ans = max(di, dj);
            }
            else if (tr)
            {
                ans = max(di, n - dj);
            }
            else if (bl)
            {
                ans = max(n - di, dj);
            }
            else if (br)
            {
                ans = max(n - di, n - dj);
            }
        }
        cout << ans << endl;
    }
    return 0;
}