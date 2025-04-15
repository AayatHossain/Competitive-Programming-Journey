#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int count = 1;
    int t;cin>>t;
    while(t--){
        double ab,ac,bc,ratio;
        cin>>ab>>ac>>bc>>ratio;
        double ad = ab * sqrt(ratio/(ratio+1));
        cout<<setprecision(20)<<"Case "<<count<<": "<<ad<<endl;
        count++;
    }
    return 0;
}