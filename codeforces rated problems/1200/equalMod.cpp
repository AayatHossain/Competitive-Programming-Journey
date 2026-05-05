#include<bits/stdc++.h>
using namespace std;
int main(){
    
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long even = 1,odd = 1, mixed = 1;
        
        vector<long long> a(n);
        for(long long i = 0; i < n; i++){
            long long m;
            cin>>m;
            a[i] = m;
            if(m%2 == 0){
                odd = 0;
            }
            if(m % 2 != 0){
                even = 0;
            }
           
           
        }
        if(odd==0 && even == 0){
            cout<<2<<endl;
        }else{
            long long flag = 0;
            for(long long i = 1; i < 58; i++){
                long long divisor = 1LL << i;
                unordered_set<long long> us;
                for(long long j = 0; j < n; j++){
                    us.insert(a[j] % divisor);
                }
                if(us.size()==2){
                    cout<<divisor<<endl;
                    flag = 1;
                    break;
                }
                if(flag==1){
                    break;
                }

            }
        }
    }
    return 0;
}