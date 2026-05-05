#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int main(){
    
    long long t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long xy = lcm(x,y);
        long long common = n / xy;
        long long c1 = n / x;
        c1 = c1 - common;
        long long c2 = n / y;
        c2 = c2 - common;
        long long sum1 = ((n*(n+1))/2) - (((n-c1)*(n-c1+1))/2);
        long long sum2 = (c2*(c2+1))/2;
        cout<<sum1-sum2<<endl;
    }
    return 0;
}