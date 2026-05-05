#include<bits/stdc++.h>
using namespace std;
#define int long long
int ok(vector<int> &a, vector<int> &b, int k, int mid){
    int count = 0;
   int i = 0, j = 0;
   int n = a.size();
   while(i < n && j < n){
    if(a[i] + b[j] < mid){
        count += (n - j);
        i++;
    }else{
        j++;0  
    }
   }
    return count <= k;
}
signed main(){
    int n,k;cin>>n>>k;
    k--;
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    
   
    int l = 0, r = 2*1e9 + 10;
    int mid;
    while(r > l+1){
        mid = l + (r-l)/2;
        if(ok(a, b, k, mid)){
            l = mid;
        }else{
            r  = mid;
        }
    }
    cout<<l<<endl;


   return 0;
}