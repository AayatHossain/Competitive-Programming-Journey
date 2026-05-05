#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        set<int> s;
        int mx = LLONG_MIN;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            s.insert(a[i]);
            mx = max(mx, a[i]);
        }
        sort(a.begin(), a.end());
        int mex = s.size();
        if(a[0]!=0){
            mex =0;
        }else{
            for(int i = 0; i < n-1; i++){
                if(a[i]==a[i+1]){continue;}
                if(a[i]!=a[i+1]-1){
                    mex = a[i]+1;
                    break;
                }
            }
        }
        // cout<<mex<<endl;
        int d = s.size();
        if(k==0){
            cout<<s.size()<<endl;
        }else{
            if(mex==s.size()){
                cout<<d+k<<endl;
            }else{
                int v = (mx+mex+1)/2;
                // cout<<v<<endl;
                if(s.find(v)!=s.end()){
                    cout<<d<<endl;
                }else{
                    cout<<d+1<<endl;
                }
            }
        }
    }
    return 0;
}