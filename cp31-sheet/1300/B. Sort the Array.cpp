#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    int i = 0, j = n-1;
    while(i<n-1 && a[i]<=a[i+1]){
        i++;
    }
    while(j>0 && a[j-1] <= a[j]){
        j--;
    }
    // cout<<i+1<<" "<<j+1<<endl;
    vector<int> b = a;
    sort(b.begin(),b.end());
    int f = 1;
    if(i < j){
        for(int k = 0; k<i; k++){
            if(a[k]!=b[k]){
                f=0;
                break;
            }
        }
        for(int k = j+1 ; k<=n-1; k++){
            if(a[k]!=b[k]){
                f=0;
                break;
            }
        }
        for(int k = i; k < j; k++){
            if(a[k]<a[k+1]){
                f=0;
                break;
            }
        }
    }else{
        i=0;j=0;
    }
    if(f){
        cout<<"yes"<<endl;
        cout<<i+1<<" "<<j+1<<endl;
    }else{
        cout<<"no"<<endl;
    }
        
    return 0;
}