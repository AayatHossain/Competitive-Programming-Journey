#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,m; cin>>n>>m;
    if(!m){
        cout<<"YES"<<endl;
        return 0;
    }
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    if(a[0]==1 || a[m-1]==n){
        cout<<"NO"<<endl;
        return 0;
    }
    int c = 1;
    for(int i = 1; i < m; i++){
        if(a[i]==a[i-1]+1){
            c++;
        }else{
            c =1;
        }
        if(c==3){
            c=-1;
            break;
        }
    }
    if(c==-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}