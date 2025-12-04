#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        map<int,int> m;
        vector<int> l(n,0);
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m[a[i]]++;
        }
        if(m[a[0]]==1)l[0]=1;
        for(int i = 1; i < n; i++){
            if(m[a[i]]==1){
                l[i]=l[i-1]+1;
            }
        }
        int mx = *max_element(l.begin(),l.end());
        if(mx==0){
            cout<<0<<endl;
        }else{
            for(int i = 0; i < n; i++){
                if(l[i]==mx){
                    cout<<i-mx+2<<" "<<i+1<<endl;
                }
            }
        }
    }
    return 0;
}