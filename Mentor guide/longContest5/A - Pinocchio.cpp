#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    int c = 1;
    while(t--){
        int n;cin>>n;
        int start = 2;
        int count = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x > start){
                int diff = x - start;
                int lie = diff/5;
                if(diff%5 >= 1){
                    lie++;
                }
                count += lie;
                start = x;
            }
        }
        cout<<"Case "<<c<<": "<<count<<endl;
        c++;
    }
    return 0;
}