#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
vector<int> a;
int n;
bool f(vector<int> &a, int g, int n, int i){
    if(g==1)return false;
    while(i < n){
        if(a[i] % g == 0){
            return false;
        }else{
            i += 2;
        }
    }
    return true;
    
}
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int g1 = a[0], g2 = a[1];
        for(int i = 0; i < n; i++){
            if(i&1){
                g2 = gcd(g2, a[i]);
            }else{
                g1 = gcd(g1, a[i]);
            }
        }
        // cout<<g1<<" "<<g2<<endl;
        bool v1 = f(a,g1,n,1);
        bool v2 = f(a,g2,n,0);
        // cout<<v1<<" "<<v2<<endl;
        if(v1){
            cout<<g1<<endl;
        }else if(v2){
            cout<<g2<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}