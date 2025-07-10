#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int>a(n);vector<int>b(n);
        for(int i = 0 ; i < n; i++){
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
        }
        vector<int> pa(n);
        vector<int> pb(n);
        pa[0] = a[0];
        pb[0] = b[0];
        for(int i = 1; i < n; i++){
            pa[i] = pa[i-1]+a[i];
            pb[i] = pb[i-1]+b[i];
        }
        // int j = 0;
        int l = -1, r = -1;
        // int f = 0;
        pair<int, int> p={0,0};
        for(int i = 0; i < n-1; i++){
        
            l = i;
            while(i+1 < n && b[i] <= b[i+1]){
                i++;
                
                int beforeA,beforeB;
                if(l-1 < 0){
                    beforeA = 0;
                    beforeB = 0;
                }else{
                    beforeA = pa[l-1];
                    beforeB = pb[l-1]; 
                }
                int sa = pa[i] - beforeA;
                int sb = pb[i] - beforeB;
                // cout<<sa<<" "<<sb<<endl;
                if(sa==sb){
                   if(p.second - p.first + 1 < i - l + 1){
                        p.first = l; p.second = i;
                   } 
                }  
            }
            // i--;
        }
        cout<<p.first+1<<" "<<p.second+1<<endl;
    }
    return 0;
}