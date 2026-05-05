#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        cout<<n<<" "<<1<<" ";
        for(int i = n-1; i >= 2; i--){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}