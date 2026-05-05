#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int s1 = 0,s2 =0;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            s1+=a[i];
        }else{
            s2+=abs(a[i]);
        }
    }
    if(s1>s2){
        cout<<"first"<<endl;
    }else if(s2 > s1){
        cout<<"second"<<endl;
    }else{
        int flag =0;
        vector<int> f;
        vector<int> s;
        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                f.push_back(a[i]);
            }else{
                s.push_back(abs(a[i]));
            }
        }
        // for(auto x: s){
        //     cout<<x<<" ";
        // }
        cout<<endl;
        
            int i = 0;
            int flag2 = -1;
            while(i < f.size() || i < s.size()){
                if(f[i] > s[i]){
                    flag = 1;
                    flag2 = 1;
                    break;
                }else if(f[i] < s[i]){
                    flag = 0;
                    flag2 = 0;
                    break;
                }else{
                    i++;
                }
            }
            if(flag2==-1){
                if(i < f.size()){
                    flag = 1;
                }else if(i < s.size()){
                    flag = 0;
                }else{
                    if(a[n-1] > 0){
                        flag = 1;
                    }else{
                        flag = 0;
                    }
                }
            }        
        if(flag){
            cout<<"first"<<endl;
        }else{
            cout<<"second"<<endl;
        }
    }
    return 0;
}