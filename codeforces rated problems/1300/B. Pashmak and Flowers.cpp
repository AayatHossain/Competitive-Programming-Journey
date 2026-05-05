#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n; 
    cin>>n;
    vector<int> a(n);
    int mx = INT_MIN;
    int mn = INT_MAX;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        mx = max(mx,a[i]);
        mn = min(mn, a[i]);
        m[a[i]]++;
    }
    int comb = m[mx]*m[mn];
    if(mx==mn){
        int v = m[mx];
        comb = (v*(v-1))/2;
    }
    cout<<mx-mn<<" "<<comb<<endl;
}