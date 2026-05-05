#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        int n, k, q;
        cin>>n>>k>>q;
        long long count = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int m;
            cin>>m;
            if(m > q){
                if(count >= k){
                    ans += ((count - k + 1)*(count - k + 2))/2;
                    
                }
                count = 0; 
            }else{
                count++;
            }
        }
        if(count >= k){
            ans += ((count - k + 1)*(count - k + 2))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}