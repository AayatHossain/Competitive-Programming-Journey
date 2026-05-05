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
        int s = -1, e = n; int mid;
        while(s + 1 < e){
            mid = s + (e-s)/2;
            if(a[mid]<=x){
                s = mid;
            }else{
                e = mid;
            }
        }
        cout<<s+1<<endl;
    }
  
    return 0;
}