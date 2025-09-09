#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
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
        int k, x;
        cin >> k >> x;
        vector<int> m;

      
        int fu = 1LL << k;

        int u = x;
        int v = fu*2 - x;

        // int moves = f(u, v, x, m);
        // cout<<u<<" "<<v<<endl;
       
        while(u != fu){
            
            
            if(u<=fu){
                m.push_back(1);
                v-=u;
                u*=2;
            }
            else{   
                m.push_back(2);
                u-=v;
                v*=2;
                
            }

        }
        reverse(m.begin(),m.end());
        cout << m.size() << endl;
        for (auto l : m)
        {
            cout << l << " ";
        }
        cout << endl;
    }
    return 0;
}