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
        int n; cin>>n;
        vector<int> a(n);
        vector<int> o,e;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i]&1){
                o.push_back(a[i]);
            }else{
                e.push_back(a[i]);
            }
        }
        sort(o.begin(),o.end());
        sort(e.begin(),e.end());

        int ans = 0;
        if(o.size()==0){
            ans = 0;
        }else{
            int i=0,j=o.size()-1;

            for(auto x: e){
                ans += x;
            }
            ans+=o[j];
            j--;

            while(i < j){
                ans+= o[j];
                i++;j--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}