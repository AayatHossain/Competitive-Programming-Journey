#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int isSame = 1;
        for(int i = 0; i < n-1; i++){
            if(a[i] != a[i+1]){
                isSame = 0;break;
            }
        }
        if(isSame && n%k==0){
            cout<<"YES"<<endl;
            continue;     
        }


        int val1 = a[0];
        int val2 = a[n-1];
        if(val1==val2){
            int c = 0;
            for(int i = 0; i < n; i++){
                if(a[i]==val1){
                    c++;
                }
            }
            if(c >= k){
                cout<<"YES"<<endl;
                continue;
            }
        }



        int c1 = 0, c2 = 0;
        int cI = -1;
        for(int i = 0; i < n; i++){
            if(a[i]==val1){
                c1++;
                if(c1==k){
                    cI = i;
                    break;
                }
            }
            
        }
        for(int i = cI; i < n; i++){
            if(a[i]==val2){
                c2++;
            }
        }

        if(c1 >= k && c2 >= k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}