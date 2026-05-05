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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[n - 1] == 0)
        {
            for (int i = 1; i <= n + 1; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }else{
            int f = 0;
            vector<int> ans;
            ans.push_back(1);
            int c = 2;
            for(int i = 1; i < n; i++){
                if(a[i]==1 && a[i-1]==0 && f == 0){
                    ans.push_back(n+1);
                    ans.push_back(c);
                    f = 1;
                }else{
                    ans.push_back(c);
                }
                c++;
            }
            if(!f){
                int o = 0;
                for(auto x: a){
                    if(x==1){
                        o++;
                    }
                }
                if(o==n){
                    cout<<n+1<<" ";
                    for(int i = 1; i <= n; i++){
                        cout<<i<<" ";
                    }
                    cout<<endl;
                }else{
                cout<<-1<<endl;

                }
            }else{
                for(auto x: ans){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
            
        }
    }
    return 0;
}