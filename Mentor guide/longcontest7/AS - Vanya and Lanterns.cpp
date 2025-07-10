#include<bits/stdc++.h>
using namespace std;
signed main(){
    double n,l;cin>>n>>l;
    double mx = -1;
    vector<double> a(n);
    for(double i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    mx = max(mx, a[0] - 0);
    mx = max(mx, l - a[n-1]);
    for(double i = 1; i < n; i++){
        mx = max(mx, (a[i] - a[i-1])/2);
    }
    cout<<fixed<<setprecision(10)<<mx<<endl;
    return 0;
}