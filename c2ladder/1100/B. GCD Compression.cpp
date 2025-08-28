#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(2*n);
        int m = 2*n;
        for(int i = 0; i < m; i++){
            cin>>a[i];
        }
        int c = 0;
        for(int i = 0; i < m-1; i++){
            for(int j = i+1; j < m; j++){
                if((a[i]&1) && (a[j]&1) && (a[i]!=-1 && a[j] != -1)){
                    cout<<i+1<<" "<<j+1<<endl;
                    a[i]=-1; a[j]=-1;
                    c++;break;
                }else if(!(a[i]&1) && !(a[j]&1) && (a[i]!=-1 && a[j] != -1)){
                    a[i]=-1; a[j]=-1;
                    cout<<i+1<<" "<<j+1<<endl;
                    c++;break;
                }
            }
            if(c==n-1){
                break;
            }
        }
    }
    return 0;
}