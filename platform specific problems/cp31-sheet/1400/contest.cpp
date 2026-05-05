#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int> s;
vector<int> a;
vector<int> b;
int n;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
       
        cin >> n;
        a.assign(n, 0);
        b.assign(n, 0);
        
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]==100){
                f=1;
            }
        }
        
        if(f==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        
    }
    return 0;
}