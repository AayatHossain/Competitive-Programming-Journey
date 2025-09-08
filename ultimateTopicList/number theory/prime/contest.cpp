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
        
        int a, b;
        cin>>a>>b;
        int mx = LLONG_MIN;
        if((a+b)%2 == 0){
            mx = a+b;
        }
        if(b&1 && a&1){
            cout<<a+b<<endl;
        }else {
            int nb = b;
            int na = a;
            while(nb>1){
                int q = nb/2;
                nb /=2;
                na = na*q;
                if((na+nb)%2 == 0){
                    mx = max(mx, na+nb); 

                }
            }
        }
        if(mx==LLONG_MIN)mx=-1;
        cout<<mx<<endl;
    }
    return 0;
}