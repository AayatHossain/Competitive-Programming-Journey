#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i= 0;i < n; i++){
        cin>>a[i];
    }
    for(int i= 0;i < n; i++){
        cin>>b[i];
    }
    int i=0,j=0;
    vector<bool> vis(n,false);
    int c = 0;
    while(i<n && j<n){
        if(!vis[a[i]-1]){
            vis[b[j]-1]=true;
            c++;
            if(a[i]==b[j]){
                c--;
                i++;
            }
            j++;
        }else{
            i++;
        }
    }
    cout<<c<<endl;
    return 0;
}