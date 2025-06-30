#include<bits/stdc++.h>
using namespace std;
bool f(vector<int> &a, int c1){
    int i = 0, j = a.size() - 1;
    while(i < j){
        if(a[i]==c1){
            i++;continue;
        }
        if(a[j]==c1){
            j--;continue;
        }
        if(a[i]==a[j]){
            i++; j--;
        }else{
            return false;
        }
    }
    return true;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int i = 0, j = n - 1;
        bool flag = true;
        while(i < j){
            if(a[i]==a[j]){
                i++;j--;
            }else{
                int c1 = a[i];
                int c2 = a[j];
                bool v1 = f(a, c1);
                bool v2 = f(a, c2);
                if(!v1 && !v2){
                    flag = 0;
                }
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}