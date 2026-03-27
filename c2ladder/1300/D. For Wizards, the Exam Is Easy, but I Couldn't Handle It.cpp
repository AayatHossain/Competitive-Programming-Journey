#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int mn = 0;
        int l = -1, r= -1;
        for(int i = 0; i < n; i++){
            int c = 0;
            int c2 = 0;
           
            for(int j= i+1; j < n; j++){
                if(a[j] < a[i]){
                    c++;
                }
                if(a[j] > a[i]){
                    c2++;
                }
                int diff = c2 - c;
                if(diff < mn ){
                    l = i; r = j;
                    mn = diff;
                }
            
            }
            
        }
        if(l==-1){
            l=0;r=0;
        }
        cout<<l+1<<" "<<r+1<<endl;
    }
    return 0;
}