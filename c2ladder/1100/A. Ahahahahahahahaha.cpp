#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i]==1){
                b.push_back(i+1);
            }
        }

       
        // for(auto x: b){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        int m = b.size();
        for(int i = 0; i <m-1; i++){
            if((b[i+1]-b[i] + 1)%2!=0){
                a[b[i+1]-2]=-1;
                b[i]=-2;
                b[i+1]=-2;
                i++;
            }else{
                b[i]=-2;
                b[i+1]=-2;
                i++;
            }
        }

        if(m!=0 && b[m-1]!=-2){
            a[b[m-1]-1]=-1;
        }

        // for(auto x: a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
C. Frog Jumps
        vector<int> c;
        for(int i = 0; i < n; i++){
            if(a[i]!=-1){
                c.push_back(a[i]);
            }
        }
        cout<<c.size()<<endl;
        for(auto x: c){
            cout<<x<<" ";
        }
        cout<<endl;

    }
    return 0;
}