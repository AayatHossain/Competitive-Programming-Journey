#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int mn = LLONG_MAX;
        int p = -1;
        for(int i = 0; i < n; i++){
            int y = a[i];
            int c = 1;
            while(y%x == 0){
                c++;
                y/=x;
            }
            if(c < mn){
                mn = c;
            }
        }
        for(int i = 0; i < n; i++){
            int y = a[i];
            int c = 1;
            while(y%x == 0){
                c++;
                y/=x;
            }
            if(c == mn){
                p = i; break;
            }
        }
        int s = 0;
        for(int i = 0; i < n; i++){
            if(i < p){
                s += (mn+1)*a[i];
            }else{
                s+=(mn)*a[i];
            }
        }
        cout<<s<<endl;

    }
}