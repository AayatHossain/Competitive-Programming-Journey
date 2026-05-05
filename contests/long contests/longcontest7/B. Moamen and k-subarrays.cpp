#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        vector<int> a(n);
        map<int,int> m;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m[a[i]] = i;
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        int c = 0;
        for(int i = 0; i < n; i++){
            int j = m[b[i]];
            c++;
            while(j < n &&  b[i]==a[j]){
                j++;
                i++;
            }
            i--;
        }
        // cout<<c<<endl;
        if(c<=k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}