#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> a(n);
       vector<int> b(n);
       for(int i = 0; i < n; i++){
            cin>>a[i];
       }
       for(int i = 0; i < n; i++){
            cin>>b[i];
       }
       vector<int> ap(2*n+1, 0);
       vector<int> bp(2*n+1, 0);
       int count = 1;
       for(int i = 0; i < n-1; i++){
            if(a[i] == a[i+1]){
                count++;
                ap[a[i]] = max(ap[a[i]], count);

            }else{
                ap[a[i]] = max(ap[a[i]], count);
                count = 1;
            }
       }
        ap[a[n-1]] = max(ap[a[n-1]], 1);

        count = 1;
       for(int i = 0; i < n-1; i++){
            if(b[i] == b[i+1]){
                count++;
                bp[b[i]] = max(bp[b[i]], count);
            }else{
                bp[b[i]] = max(bp[b[i]], count);
                count = 1;
            }
       }
        bp[b[n-1]] = max(bp[b[n-1]], 1);


        // for(int i = 0; i <= 2*n; i++){
        //     cout<<ap[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i <= 2*n; i++){
        //     cout<<bp[i]<<" ";
        // }
        // cout<<endl;



       int val = 0;
       int ans = -1;
       for(int i = 0; i <= 2*n; i++){
            val = ap[i] + bp[i];
            ans = max(ans, val);
       }
       if(ans==0){
            ans = 1;
       }
       cout<<ans<<endl;
       
       
    }
    return 0;
}