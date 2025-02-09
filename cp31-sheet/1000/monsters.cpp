#include<bits/stdc++.h>
using namespace std;

bool cC(const pair<int, int> &a, const pair<int, int> &b){
     if(a.first != b.first){
          return a.first > b.first;
     }
     return a.second < b.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       vector<pair<int,int>> a(n);
       for(int i = 0; i < n; i++){
            int m;
            cin>>m;
            m = m % k;
            if(m==0){
               m = k;
            }
            a[i] = make_pair(m, i);
       }
       sort(a.begin(), a.end(), cC);
      
       for(int i = 0; i < n; i++){
            cout<<a[i].second + 1<<" ";
       }
       cout<<endl;
       
       
    }
    return 0;
}