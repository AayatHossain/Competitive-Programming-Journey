#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int v1=-1,v2=-1,v3=-1;
        int mx = INT_MIN;
        for(int i =2; i*i <= n; i++){
            int x=n;
            int c = 1;
            while(x > 1 && x%i==0){
                x/=i;
                c++;
            }
            if(x!=0){
                c--;
            }
            if(c > 1){
                if(c > mx){
                    v1 = i;
                    v2 = x;
                    v3 = c;
                    mx = c;
                }
            }
        }
        if(v1==-1 || v2==-1){
            cout<<1<<endl;
            cout<<n<<endl;
        }
        else if(v2==0){
            cout<<v3<<endl;
            for(int i = 0; i < v3; i++){
                cout<<v1<<" ";
            }
            cout<<endl;
        }else{
            cout<<v3<<endl;
            for(int i = 0; i < v3-1; i++){
                cout<<v1<<" ";
            }
            cout<<v2*v1<<" ";
            cout<<endl;
        }
    }
    return 0;
}