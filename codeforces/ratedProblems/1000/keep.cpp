#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int indx = -1;
        int curr = a[0];
        int sec = -1; string ans; ans += '1';
        for(int i = 1; i < n; i++){
            if(a[i] >= curr){
                ans += '1'; curr = a[i];
            }else if(a[i] < curr && a[i] <= a[0]){
                ans += '1';
                sec = a[i];
                indx = i; break;
            }else{
                ans += '0';
            }
        }
        // cout<<sec<<" "<<indx<<endl;
        if(sec != -1){
            for(int i = indx + 1; i < n; i++){
                if(a[i] >= sec && a[i] <= a[0]){
                    ans+='1'; sec = a[i];
                }else{
                    ans+='0';
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}