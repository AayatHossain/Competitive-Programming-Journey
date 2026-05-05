#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isGood(vector<int> &a, int n, double mid, int k) {
    int pc = 0;
    for(int i = 0; i < n; i++){
        pc += (a[i] / mid);
    }
    return pc >= k;
}

signed main(){
    int n, k; cin>>n>>k;
    vector<int> a(n); 
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    double l = 0; //l is good, can cut 0 size pieces infinitely
    double r = 1e8; // r is bad, greater than max length, not a single piece
   
    double mid;
    for(int i = 0; i < 100; i++){
        mid = l + (r - l)/2;
        if(isGood(a,n,mid,k)){
            l = mid;
        }else{
            r = mid;
        }

    }
    cout<<setprecision(7)<<l<<endl;
    
  
    return 0;
}