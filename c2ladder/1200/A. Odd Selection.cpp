#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        int ans = 0;
        for(int i= 1; i <= odd; i++){
            if(i&1){
                if(even >= x - i)ans = 1;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else{cout<<"NO"<<endl;}
    }
    return 0;
}