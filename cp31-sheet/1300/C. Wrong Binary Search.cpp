#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> a(n);
        int c1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='1'){
                c1++;
            }
            a[i]=i+1;
        }
        int c2 = 0;
        for(int i = 1; i < n; i++){
            if(s[i]=='0' && s[i-1] == '0'){
                int tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                i++;
                c2 += 2;
            }
        }
        if(c1==0){
            cout<<"YES"<<endl;
            for(int i = n; i >= 1; i--){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(c1+c2==n){
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