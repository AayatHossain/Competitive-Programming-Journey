#include<bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int m, vector<pair<int,int>> &a, int n){
    int c = m;
    for(int i = 0; i < n; i++){
        // cout<<c<<endl;
        if(c >= a[i].first){
            c += a[i].second;
        }else{
            return false;   
        }
        // if(m==4){
        //     cout<<c<<endl;
        // }
    }
    return true;
}

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first==p2.first){
        return p1.second>p2.second;
    }
    return p1.first < p2.first;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++){
            int k; cin>>k;
            int mx= LLONG_MIN;
           
            int v = -1;
            for(int j = 0; j < k; j++){
                int x; cin>>x;
                 v = x- j + 1;
                if (v > mx){
                    mx = v;
                }
                
            }
            a[i] = {mx,k};
            // cout<<mx<<" "<<v<<endl;
        }
        sort(a.begin(),a.end(),cmp);
        // for(auto x: a){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        int l = 0, r = 1e9+1;
        int m;
        while(l+1<r){
            m = l + (r-l)/2;
            if(ok(m,a,n)){
                r = m;
            }else{
                l = m;
            }
        }
        // cout<<ok(5,a,n)<<endl;
        
        cout<<r<<endl;

    }
    return 0;
}