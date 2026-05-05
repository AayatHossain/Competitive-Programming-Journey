#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,r,b;cin>>n>>r>>b;
        int c = -1;
        if(b==1){
            c=n/2;
        }else{
            if(n%2==0){
                if(b%2==0){
                    c = n/b - 1;
                }else{
                     c= n/b;
                }
            }else{
                c = n/b - 1;
            }
        }
        if(c==1){
            c++;
        }
        // cout<<c<<endl;
        string s;
        int count = b;
        for(int i = 1; i <= n; i++){
            if(i % c == 0 && count > 0 && i != 1){
                s += 'B';
                count--;
            }else{
                s+='R';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}