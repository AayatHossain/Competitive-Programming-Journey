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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
       int n, k; cin>>n>>k;
        map<int,int> s;
        map<int,int> t;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            int v = min(x%k, (k-x%k)%k);
            s[v]++;
        }
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            int v = min(x%k, (k-x%k)%k);
            t[v]++;
        }
        int f = 1;
        for(auto x: s){
            
            if(t[x.first]!=x.second){
               
                f=0;break;
            }

        }
      
        // print(s);
        // print(t);
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}