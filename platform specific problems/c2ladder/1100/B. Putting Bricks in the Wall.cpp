#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<pair<int, int>> ans;
        char t1, t2, b1, b2;
        t1 = a[0][1];
        t2 = a[1][0];

        b1 = a[n - 2][n - 1];
        b2 = a[n - 1][n - 2];

        char tv, bv;

        if (t1 == t2)
        {
            tv = t1;
            if (b1 == tv)
            {
                ans.push_back({n - 2 + 1, n - 1 + 1});
            }
            if (b2 == tv)
            {
                ans.push_back({n - 1 + 1, n - 2 + 1});
            }
        }
        else if (b1 == b2)
        {
            bv = b1;
            if (t1 == bv)
            {
                ans.push_back({0 + 1, 1 + 1});
            }
            if (t2 == bv)
            {
                ans.push_back({1 + 1, 0 + 1});
            }
        }else{
            char fv = '0';
            if(t1!=fv){
                ans.push_back({0 + 1, 1 + 1});
                
            }
            if(t2!=fv){
                ans.push_back({1 + 1, 0 + 1});

            }
            if(b1==fv){
                ans.push_back({n - 2 + 1, n - 1 + 1});

            }
            if(b2==fv){
                ans.push_back({n - 1 + 1, n - 2 + 1});

            }
        }
        cout<<ans.size()<<endl;
        for(auto x: ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}