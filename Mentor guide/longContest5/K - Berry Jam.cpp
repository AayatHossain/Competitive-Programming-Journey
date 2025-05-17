#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        a.resize(2*n+1);
        for(int i = 1; i <= 2*n; i++){
            cin>>a[i];
        }
        map<int,int> dr;
        dr[0] = 0;
        int curr = 0;
        for(int i = n+1; i<= 2*n; i++){
            if(a[i]==1){
                curr--;
            }else{
                curr++;
            }
            if(!dr.count(curr)){
                dr[curr] = i - n;
            }
        }
        int c1 = 0, c2 = 0;
        for(auto x: a){
            if(x==1){
                c1++;
            }else if(x==2){
                c2++;
            }
        }
        int d = c2 - c1;
        curr = 0;
        int ans = 2*n;
        for(int i = n; i >= 1; i--){
            if(a[i] == 1){
                curr--;
            }else{
                curr++;
            }
            if(dr.count(d - curr)){
                ans = min(ans, n - i + 1  + dr[d-curr]);
            }
        }
        if(dr.count(d)){
            ans = min(ans, dr[d]);
        }
        cout<<ans<<endl;
    }
    return 0;
}