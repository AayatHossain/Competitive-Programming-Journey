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
        vector<pair<int, vector<int>>> a(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i].first = x;
            for (int j = 0; j < x; j++)
            {
                int y;
                cin >> y;
                a[i].second.push_back(y);
            }
        }
        int N = 2e5 + 1;
        vector<int> vis(N, false);
        sort(a.begin(), a.end(),
     [](const pair<int, vector<int>> &x, const pair<int, vector<int>> &y) {
        
         if (x.first != y.first) 
             return x.first > y.first;

        
         return x.second < y.second; 
     });

        for(int i = 0; i < n; i++){
            cout<<a[i].first<<" ";
            for(int v: a[i].second){
                cout<<v<<" ";
            }
        cout<<endl;
            
        }

        int p = 0;
        for (int i = 0; i < n; i++)
        {
            int f = 1;
            for (int v : a[i].second)
            {
                if (!vis[v])
                {
                    f = 0;
                    break;
                }
            }
            if (!f)
            {
                for (int v : a[i].second)
                {
                    vis[v]=true;
                }
            }else{
                p=1;
                break;
            }
            
        }
        if(p){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}