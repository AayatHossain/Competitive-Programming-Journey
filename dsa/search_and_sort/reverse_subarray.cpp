#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int l = -1;
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            l = i;
            break;
        }
    }
    if(l==-1){
        cout<<"Yes"<<endl;
        return 0;
    }
    int r=-1;
    for(int i = l; i < n-1; i++){
        if(a[i] >= a[i+1]){
            r = i+1;
        }else{
            break;
        }
    }
    // cout<<l<<" "<<r<<endl;
    while(l < r){
        swap(a[l],a[r]);
        l++;r--;
    }
    int f = 1;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            f = 0;
            break;
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}