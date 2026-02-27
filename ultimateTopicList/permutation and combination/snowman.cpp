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

        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        for(int i = 0; i < n; i++){
            cin>>c[i];
        }

        int c1 = 0, c2 = 0;
        for(int i = 0; i <n; i++){
            int k = i;
            int f = 1;
            for(int j = 0; j < n; j++){
                if(c[k] <= b[j]){
                    f = 0;
                    break;
                }
                k++;
                if(k==n)k=0;
            }
            if(f){
                c2++;
            }
        }


        for(int i = 0; i <n; i++){
            int k = i;
            int f = 1;
            for(int j = 0; j < n; j++){
                if(b[k] <= a[j]){
                    f = 0;
                    break;
                }
                k++;
                if(k==n)k=0;
            }
            if(f){
                c1++;
            }
        }
        cout<<c1*n*c2<<endl;                                                                        



    }
    
    
    return 0;
}