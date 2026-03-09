#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        // cout<< 6/7 + 1/6 + (66-7)/5 + (77-66)/4 + (666-77)/3 + (777-666)/2 + (1987-777)<<endl;
        // // cout<< 6%7 + 1%6 + (66-7)%5 + (77-66)%4 + (666-77)%3 + (777-666)%2 <<endl;

        // cout<< 13/3 + (37-13)/2 + 3 <<endl;
        int n,m,l; cin>>n>>m>>l;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int s = (l - a[n-1]);
        for(int i  = 1; i < n; i++){
            s += (a[i]-a[i-1])/(n-i+1)  + (a[i]-a[i-1])%(n-i+1);
        }

        // for(int i  = 0; i < n; i++){
        //     s += (a[i]);
        // }
        cout<<s-m<<endl;
        

       


    }
    return 0;
}