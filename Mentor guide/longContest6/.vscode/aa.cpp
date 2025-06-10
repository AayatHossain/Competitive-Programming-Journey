#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+7;
int a[N];
int n;
int ps(int x){
    int y = sqrt(x);
    return y*y==x;
}
int f(int i, int total){
    if(i==n && ps(total)){
        // cout<<total<<endl;
        return 1;
    }
    if(i==n){
        return 0;
    }
    return f(i+1, total*a[i])+f(i+1, total);
}
signed main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<f(0,1)-1<<endl;
}