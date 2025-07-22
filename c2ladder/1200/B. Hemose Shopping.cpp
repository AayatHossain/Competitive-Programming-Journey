#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int f = 1;
        vector<int> b = a;
        sort(b.begin(), b.end());
        for(int i = 0; i <n ;i++){
            if(a[i] != b[i]){
                int left = (i+1) - x;
                int right = (i+1) + x;
                // if(i==2){
                //     cout<<left<<" "<<right<<endl;
                // }
                if(!(left >= 1 || right <= n)){
                    f = 0;
                    break;
                }
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}