#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i =0; i < n; i++)cin>>a[i];
    int c = 0;
    vector<int> b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            c++;
        }
    }
    if(c <= 2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}