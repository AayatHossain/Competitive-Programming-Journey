#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        int fa =1;
        int fb =1;
        for(int i =1;i<=a;i++){
            fa*=i;
        }
        for(int i =1;i<=b;i++){
            fb*=i;
        }
        int n = fa/fb;
        int c=0;
        // cout<<n<<endl;
        while(n > 1){
            for(int i=2;i<=n;i++){
                if(n%i==0){
                    c++;
                    n/=i;
                    break;
                }
            }
        }
        cout<<c<<endl;
    }
    return 0;
}