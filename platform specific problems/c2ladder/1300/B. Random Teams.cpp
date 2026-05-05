#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m; cin>>n>>m;
    int maxp = n - (m-1);
    int mx = (maxp*(maxp-1))/2;

    int minp = (n+m-1)/m;
    int cmin = (minp*(minp-1))/2;

    int q = n/m;
    int r = n%m;
    int teamnoextra = ((q*(q-1))/2)*(m-r);
    int teamextra = (((q+1)*(q))/2)*(r);
    int mn = teamextra + teamnoextra;

    cout<<mn<<" "<<mx<<endl;
    return 0;
}