#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        // set<int> pos;
        // set<int> neg;
        map<int, int> pos;
        map<int, int> neg;
        int mn = LLONG_MIN;
        int mx = LLONG_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] < 0){
                mn = max(mn, a[i]);
            }else{
            
                neg[mn]++;
                mn = LLONG_MIN;
            }
            if(a[i] > 0){
                mx = max(mx, a[i]);
                // cout<<mx<<endl;

            }else{
                // cout<<mx<<endl;
                pos[mx]++;
                mx = LLONG_MIN;
            }
        }
        pos[mx]++;
        neg[mn]++;

        pos.erase(LLONG_MIN);
        neg.erase(LLONG_MIN);
        int s = 0;
        for(auto x: pos){
            // cout<<x<<endl;
            s+=x.first*x.second;
        }
        for(auto x: neg){
            // cout<<x<<endl;
            s+=x.first*x.second;
        }
        cout<<s<<endl;
    }
    return 0;
}