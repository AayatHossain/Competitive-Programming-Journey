#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
        
        int t;
        cin>>t;
        while(t--){
            int x; cin>>x;
            int f = 0;
            for(int i = 1; i < cbrt(x); i++){
                int left = x - (i*i*i);
                int l = 1, r = cbrt(left);
                while(r >= l){
                    int mid = l + (r-l)/2;
                    if(mid*mid*mid == left){
                        f = 1;
                        break;
                    }else if(mid*mid*mid < left){
                        l = mid + 1;
                    }else{
                        r = mid -1;
                    }
                }
                if(f){
                    break;
                }
            }
            if(f){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }

        }
    
    return 0;
}