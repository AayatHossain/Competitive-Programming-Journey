#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i =0; i < n; i++)cin>>a[i];
    for(int i =0; i < m; i++)cin>>b[i];
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            cout<<a[i]<<" ";
            i++;
        }else{
            cout<<b[j]<<" ";
            j++;
        }
    }
    if(i == n){
        while(j < m){
            cout<<b[j]<<" ";
            j++;
        }

A. Segment with Small Sum

        
    }
    if(j == m){
        while(i < n){
            cout<<a[i]<<" ";
            i++;
        }
    }
    return 0;
}