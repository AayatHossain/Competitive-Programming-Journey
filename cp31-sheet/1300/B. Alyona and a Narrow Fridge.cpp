#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n,h; cin>>n>>h;
    vector<int> a(n);
    for(int i = 0; i< n; i++)cin>>a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        vector<int> b;
        for(int j = 0; j < i; j++){
            b.push_back(a[j]);
        }
        sort(b.begin(),b.end());
        int s = 0;
        int f = 1;
        for(int j = b.size()-1; j>=0; j-=2){
            s+=b[j];
            if(s>h){
                f = 0;
            }
        }
        if(!f){
            break;
        }
        ans = i;
    }
    cout<<ans<<endl;
    return 0;
}