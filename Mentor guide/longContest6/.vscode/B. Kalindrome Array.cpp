#include<bits/stdc++.h>
using namespace std;
bool f(vector<int> &a, int c1){
    string s;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != c1){
            s+=to_string(a[i]);
        }
    }
    // cout<<s<<endl;
    int i = 0, j = s.size() -1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }else{
            i++; j--;
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