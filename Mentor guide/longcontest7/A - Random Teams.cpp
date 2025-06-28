#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;cin>>n>>m;
    int v1 = n-(m-1);
    int mx = (v1*(v1-1))/2;

    int v2 = n/m;
    int left = n - (m*v2);

    int g1 = left;
    int g2 = m - g1;
    v1 = v2 + 1;
    int mn1 = ((v1*(v1-1))/2)*g1;
    int mn2 = ((v2*(v2-1))/2)*g2;

    cout<<mn1+mn2<<" "<<mx<<endl;
    return 0;
}