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

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        vector<int> a(n);
        for(int i =0 ;i < n; i++){
            cin>>a[i];
        }
        int ans = -1;
        for(int i = 0; i <= 101; i++){
            int f = 1;
            for(int j = 0; j < n; j++){
                if(a[j]==i){
                    f = 0;
                    break;
                }
            }

            if(f){
                ans = i;
                break;Sliding Window Minimum

            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}