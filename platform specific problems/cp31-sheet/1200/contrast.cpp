#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);
        for(int i = 0; i < n; i++){cin>>a[i];}
        int size = unique(a.begin(), a.end()) - a.begin();
        // cout<<size<<endl;
        int ans = size;
        for(int i = 0; i+2 < size; i++){
            ans -= (a[i] > a[i+1] && a[i+1] > a[i+2]);
            ans -= (a[i] < a[i+1] && a[i+1] < a[i+2]);
        }
        cout<<ans<<endl;
    }
    return 0;
}