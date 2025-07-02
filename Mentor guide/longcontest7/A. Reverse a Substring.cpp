#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin>>n;
    string s; cin>>s;
    vector<char> a(n);
    a[n-1] = s[n-1];
    for(int i = n-2; i>= 0; i--){
        a[i] = min(s[i], a[i+1]);
    }
    char c1, c2 = '0';
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
         c1 = s[i];
         c2 = a[i];
        // cout<<c1<<" "<<c2<<endl;
        if(c1 > c2){
            l = i;
            break;
        }
    }
        // cout<<c1<<" "<<c2<<endl;

    if(c2 != '0'){
        for(int i = l+1; i < n; i++){
            if(s[i]==c2){
                r = i;
                break;
            }
        }
    }
    if(l==-1 || r == -1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;

    cout<<l+1<<" "<<r+1<<endl;

    }
    return 0;
}