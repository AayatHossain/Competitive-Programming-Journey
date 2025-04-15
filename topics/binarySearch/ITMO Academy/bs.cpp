#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin>>n>>k;
    vector<int> a(n);
    // vector<int> q(k);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < k; i++){
     
        int x; cin>>x;
        int l = -1, r = n; int mid;
        while(l + 1 < r){
            mid = l + (r-l)/2;
            if(a[mid] < x){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(r < n && a[r] == x){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
  
    return 0;
}