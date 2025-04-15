#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a < b){
            cout<<1<<endl;
        }else if(a==b){
            cout<<2<<endl;
        }else{
            int newB;
            if(b==1){
                newB=2;
            }else{
                newB = b;
            }
            int newA = a;
            int ans = INT_MAX;
            while(newB <= b+30 && newB <= a+1){
                int count1 = newB - b;
                while(newA > 0){
                    newA = newA/newB;
                    count1++;
                } 
                newA = a;
                ans = min(ans, count1);
                newB++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}