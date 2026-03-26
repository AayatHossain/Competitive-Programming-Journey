#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n; cin>>n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int p = -1;
        if(i%2 == 0)p = 1;
        int x=  p * (i*i*i);
        ans += x;
    }
    cout<<ans<<endl;

    return 0;
}