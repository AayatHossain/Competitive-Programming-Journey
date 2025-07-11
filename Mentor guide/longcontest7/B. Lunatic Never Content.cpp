#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int i = 0, j = n - 1;
        int g = 0;
        while(i < j){
            int diff = abs(a[i] - a[j]);
            g = gcd(diff, g);
            i++;j--;
        }
        cout<<g<<endl;
    }
    return 0;
}