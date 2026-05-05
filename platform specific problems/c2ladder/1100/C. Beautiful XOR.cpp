#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        int c = 0;
        for (int i = 0; i < 32; i++)
        {
            int m = (1 << i);
            if ((b & m) && !(a & m))
            {
                c = c | m;
            }
        }

        if(c > a){
            cout<<-1<<endl;
            continue;
        }

        vector<int> ans;
        ans.push_back(c);
        a ^= c;
        c = 0;

         if(a==b){
            cout<<1<<endl;
            cout<<ans[0]<<endl;
            continue;
        }

        for (int i = 0; i < 32; i++)
        {
            int m = (1 << i);
            if ((a & m) && !(b & m))
            {
                c = c | m;
            }
        }

        ans.push_back(c);
        a ^= c;

        if(a==b){
            cout<<ans.size()<<endl;
            for(auto x: ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}