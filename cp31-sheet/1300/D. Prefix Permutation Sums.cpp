#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> b(n-1);
        for(int i = 0; i < n-1; i++){
            cin>>b[i];
        }
        vector<bool>v(n+1,false);
        vector<int> cand;
        for(int i = 0; i < n-1; i++){
            int d;
            if(i==0){
                d = b[i];
            }else{
                d = b[i]-b[i-1];
            }
            // cout<<d<<endl;
            if(d<=n && !v[d]){
                v[d]=true;
            }else{
                cand.push_back(d);
            }
        }
        int l1=-1,l2=-1;
        int f = 1;
        for(int i = 1; i <= n; i++){
            if(!v[i]){
                if(l1==-1){
                    l1 = i;
                }else{
                    l2 = i;
                }
                f=0;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            if(cand.size()==0 || l1==-1 || l2==-1 || l1+l2==cand[0]){
                cout<<"YES"<<endl; 
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}