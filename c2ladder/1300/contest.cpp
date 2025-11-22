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
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        for(int i = 0; i < n; i++){
            cin>>b[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= a[i];
            ans ^= b[i];
        }
        if(ans==0){
            cout<<"Tie"<<endl;
        }else{
            int v = -1;
            for(int i = 0; i < n; i++){
                if((a[i] ^ b[i])==1)v=i;
            }
            if(v&1){
                cout<<"Mai"<<endl;
            }else{
                cout<<"Ajisai"<<endl;

            }
        }
        
    }
    return 0;
}