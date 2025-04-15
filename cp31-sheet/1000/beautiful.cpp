#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
      long long n,k,b,s; cin>>n>>k>>b>>s;
      vector<long long> a(n, 0);
      long long div = 0;
      long long flag = 1;
      a[n-1] = s;
      div = s / k;
      
      if(div< b){
        flag = 0;
    }
      for(long long i = n-2; i >= 0; i--){
       
       
        if(div == b){
            flag = 1;
            break;
        }else{
            a[i] = k-1;
            a[n-1] -= k-1;
            div = a[n-1] / k;

        }
        
      }
      if(div != b){
        flag = 0;
      }
      if(flag){
        for(long long i = 0; i < n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
      }else{
        cout<<-1<<endl;
      }
    }
    return 0;
}