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
        int n,x;
        cin >> n>>x;
        string s; cin>>s;
        int l = 0, r = 0;
        x--;
        
        int ans = 0;
        if(x==0 || x == n-1){
            ans = 1;
        }
        else{
            int lx=INT_MIN,rx=INT_MAX;
            for(int i = x; i < n; i++){
                if(s[i]=='#'){
                    rx=i;break;
                }
            }
            for(int i = x; i >= 0; i--){
                if(s[i]=='#'){
                    lx=i;break;
                }
            }
           
// 1
// 12 7
// ###......###
            
            if(lx==INT_MIN && rx==INT_MAX){
                ans = 1;
            }else{
            ans =  max(min(x+1, n-rx+1), min(lx+2, n-x)) ;

            }
            
        }
        cout<<ans<<endl;
        

    }
    return 0;
}