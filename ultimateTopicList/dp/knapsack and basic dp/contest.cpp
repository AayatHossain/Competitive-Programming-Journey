#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        string a,b;
        cin>>n;
        cin>>a;
        cin>>m;
        cin>>b;
        string ans = a;
        for(int i = 0; i < m; i++){
            char x; cin>>x;
            if(x=='D'){
                ans+=b[i];
            }else{
                char ch = b[i];
                ans = ch + ans;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}