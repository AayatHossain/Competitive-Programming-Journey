#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, s; cin>>n>>s;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int cs = 0;
    int j = 0;
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        cs += a[i];
        while(j <=i && cs > s){
            cs-=a[j];
            j++;
        }
        mx = max(mx, i-j+1);
    }
    if(mx==INT_MIN){
        mx = 0;
    }
    cout<<mx<<endl;
    return 0;
}