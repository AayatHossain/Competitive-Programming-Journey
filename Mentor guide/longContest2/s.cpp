#include<bits/stdc++.h>
using namespace std;
#define int long long
int ok(vector<vector<int>> &a,int n, double mid, double t){
    double time = 0;

    for(int i = 0; i < n; i++){
        int d = a[i][0];
        int s = a[i][1];
        if(s + mid <= 0){
            // cout<<mid<<" "<<s+mid<<endl;
            return 1;
        }
        time += (double) d/(s+mid); 
    }
    return time >= t;
}
signed main(){
    int n,t;cin>>n>>t;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i = 0; i < n; i++){
        cin>>a[i][0]>>a[i][1];
    }
    double l = -1e9, r = 1e9;
    double mid;
    for(int i = 0; i < 100; i++){
        mid = l + (r - l) /2;
        // cout<<mid<<endl;
        // cout<<mid<<endl;
        if(ok(a,n,mid, t)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<fixed<<setprecision(20)<<l<<endl;
    // cout<<fixed<<setprecision(20)<<mid<<endl;
    // cout<<setprecision(20)<<r<<endl;
}