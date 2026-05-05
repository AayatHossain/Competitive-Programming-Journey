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

struct node
{
    int l = -1;
    int r = -1;
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int a,b; cin>>a>>b;
        int ans = -1;
        if(b&1){
            if(a&1){
                ans = a*b+1;
            }
        }else{
            int k = b/2;
            int s = a*k + b/k;
            if(s%2==0){
                ans = s;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}