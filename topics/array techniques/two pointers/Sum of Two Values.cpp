#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,s; cin>>n>>s;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        a[i] = {x,i};
    }
    sort(a.begin(),a.end());
    int i = 0,j=n-1;
    int k = -1,l = -1;
    while(i < j){
        int cs = a[i].first + a[j].first;
        if(cs > s){
            j--;
        }else if(cs < s){
            i++;
        }else{
            k = a[i].second;
            l = a[j].second;
            break;
        }
    }
    if(k==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<k+1<<" "<<l+1<<endl;
    }
    return 0;
}