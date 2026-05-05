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
        int cl = 0, cr = 0;
        int i = 0, j = n -1;
        while(i < n && a[i] == b[i]){
            i++;
            cl++;
        }
        while(j>=0 && a[j]==b[j]){
            j--;
            cr++;
        }
        int l = i + 1;
        int r = j +1;
        // cout<<l<<" "<<r<<endl;
        int mx = b[j];
        int mn = b[i];
        // cout<<mn<<" "<<mx<<endl;

        while(i > 0){
            int mn2 = a[i-1];
            if(mn2<=b[i]){
                i--;
                mn = mn2;
            }else{
                break;
            }
        }
        while(j < n-1){
            int mx2 = a[j+1];
            if(mx2 >= b[j]){
                j++;
                mx = mx2;
            }else{
                break;
            }
        }
        cout<<i+1<<" "<<j+1<<endl;
        


    }
    return 0;
}