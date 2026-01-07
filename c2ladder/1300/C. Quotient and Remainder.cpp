#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int m, vector<int> &a,vector<int> &b,int k){
    int i = 0, j = m-1;
    while(i < m){
        int x = (b[j]+1)*a[i] + b[j];
        if(x > k)return false;
        i++;j--;
    }
    return true;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int c = n;
        int l = 0, r = n+1,m;
        while(l+1<r){
            m = l+(r-l)/2;
            if(ok(m,a,b,k)){
                l = m;
            }else{
                r = m;
            }
        } 
        cout<<l<<endl;

    }
}