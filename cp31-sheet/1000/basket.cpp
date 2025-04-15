#include<bits/stdc++.h>
using namespace std;

int main(){
    
      long long n,d;cin>>n>>d;vector<long long>a(n);for(long long i = 0; i < n; i++){cin>>a[i];}sort(a.begin(), a.end());
      long long power = 0; long long count = 0;
      int j = 0; int i = n-1;
        while(j < i){
            power = a[i];
            while(j < i && power <= d){
                power += a[i];
                j++;
                
            }
            i--;
            if(power > d){
                count++;
                // cout<<power<<endl;
            }
        }
        if(a[i] > d){
            count++;
        }
      
      cout<<count<<endl;
    
    
    return 0;
}