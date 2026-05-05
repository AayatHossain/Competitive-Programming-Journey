#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int c = n;
        vector<int> a(n);
        int z = 1;
        for(int i = 0; i < n; i++){
            if(z==1 && s[i] == '1'){
                z=0;
            }
            if(s[i]=='0'){
                a[i]=c;
                c--;
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i]=='1'){
                a[i]=c;
                c--;
            }
        }
        int f = 1;
        c=1;
        for(int i = 1; i < n; i++){
            if(s[i]==s[i-1] && s[i]=='1'){
                c++;
                if(c==k){
                    f=0;
                    break;
                }
            }else{
                c=1;
            }
        }
        if((f && k != 1 && n != 1) || z==1){
            cout<<"YES"<<endl;
            for(auto x: a){
                cout<<x<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }
    return 0;
}