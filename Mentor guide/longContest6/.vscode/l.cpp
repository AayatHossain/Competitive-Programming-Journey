#include<bits/stdc++.h>
using namespace std;
int n;
double a[3000];
double f(int i, int h, int t, double total){
    if(i==n && h > t){
        return total;
    }
    if(i==n && h <= t){
        return 0;
    }
    return f(i+1,h+1,t,total*a[i])+f(i+1,h,t+1,total*(1-a[i]));
}
signed main(){
   cin>>n;
   for(int i = 0; i < n; i++){
    cin>>a[i];
   }
   cout<<fixed<<setprecision(9)<<f(0,0,0,1)<<endl;

    return 0;
}