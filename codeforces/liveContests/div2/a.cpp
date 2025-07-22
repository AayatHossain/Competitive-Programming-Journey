#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
       int a, b, k; cin>>a>>b>>k;
       if((k >= a && k >= b ) || a == b){
        cout<<1<<endl;
       }else{
            int g = gcd(a,b);
            int na = a/g;
            int nb = b/g;
            // cout<<na<<" "<<nb<<endl; 
            if(na <= k && nb <= k){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
       }
    }
}