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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int c = n * n;
        int l = c - k;
        if (l == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        char a[n][n];
        if (l != 0)
        {
            a[0][0]='R';
        }else{
            a[0][0]='D';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==0 && j==0){
                    cnt++;continue;
                }

                if (cnt >= l)
                {
                    a[i][j] = 'D';
                }
                else
                {
                    if (i == 0)
                    {
                        a[i][j] = 'L';
                    }
                    else
                    {
                        a[i][j] = 'U';
                    }
                }
                cnt++;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}