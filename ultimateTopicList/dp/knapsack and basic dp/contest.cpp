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
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> m;
        int z=0,o=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]==0)z++;
            if(a[i]==1)o++;
            m[a[i]]++;
            
        }
        int p = min(z,o);
        int ans = p*2;
        m[0] -= p;
        m[1] -= p;
        for(auto x: m){
            if(x.first==0 && x.second > 0){ans+=x.second; continue;}
            ans += x.second*x.first;
        }
        cout<<ans<<endl;

    }
    return 0;
}