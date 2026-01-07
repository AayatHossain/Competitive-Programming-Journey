#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        for(int i = 0; i < n; i++)cin>>b[i];
        for(int i = 0; i < n; i++)cin>>c[i];

        int c2 = 0;
        for(int i = 0; i < n; i++){
            int f = 1;
            int k = 0;
            for(int j = i; j < n+i; j++){
                if(b[k]>=c[j%n]){
                    f=0;
                    break;
                }
                k++;
            }
            // cout<<f<<endl;
            if(f)c2++;
        }
        int c1 = 0;
        for(int i = 0; i < n; i++){
            int f = 1;
            int k = 0;
            for(int j = i; j < n+i; j++){
                if(a[k]>=b[j%n]){
                    f=0;
                    break;
                }
                k++;
            }
            if(f)c1++;
        }
        // cout<<c1<<" "<<c2<<endl;
        cout<<c1*c2*n<<endl;
    }
    return 0;
}