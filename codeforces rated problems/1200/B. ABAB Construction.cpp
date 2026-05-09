#include<bits/stdc++.h>
using namespace std;

bool f(string t, string s, int n){
    int ind = 0;
    int i = 0, j = n-1;
    while(i <= j){
        if(s[ind]=='?'){
            i++;
        }else if(s[ind]==t[i]){
            i++;
        }else if(s[ind]==t[j]){
            j--;
        }else{
            return false;
        }
        ind++;
    }
    return true;
}

signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        string s1;
        for(int i = 0; i < n; i++){
            if(i&1){
                s1+='b';
         
            }else{
                s1+='a';
                
            }
        }
        cout<<s1<<endl;
        bool f1 = f(s1,s,n);
        if(f1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}