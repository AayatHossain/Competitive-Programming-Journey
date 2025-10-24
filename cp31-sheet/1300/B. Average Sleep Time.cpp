#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int s = 0;
    int t = 0;
    for(int i = 0; i < n; i++){
        if(i<k){
            s+=a[i];
            if(i==k-1){
                t+=s;
            }
        }else{
            s-=a[i-k];
            s+=a[i];
            t += s;
        }
        
    }
    double res = (double) t/(n-k+1);
    cout<<fixed<<setprecision(6)<<res<<endl;
    return 0;
}