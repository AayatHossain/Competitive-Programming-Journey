#include <bits/stdc++.h>
using namespace std;
#define int long long
int ok(double x,double y, double c, double w){
    double r1 = sqrt(x*x - w*w);
    double r2 = sqrt(y*y - w*w);
    double f1 = 1/r1;
    double f2 = 1/r2;
    double f3 = 1/c;
    return f1+f2 <= f3;
}

signed main()
{
    int count = 1;
    int t;
    cin >> t;
    while (t--)
    {
        double x,y,c;
        cin >> x>>y>>c;
        double l = 0, r = min(x,y);
        double mid;
        for(int i = 0; i < 100; i++){
            mid = l+(r-l)/2;
            if(ok(x,y,c,mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<setprecision(10)<<"Case "<<count<<": "<<l<<endl;
        count++;
    }
    return 0;
}