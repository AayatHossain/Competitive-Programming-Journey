#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
       int n;cin>>n;string s;cin>>s;
       int count = 1; int zeroes = 0;
       for(int i = 0; i < n; i++){
        if(s[i]=='0'){zeroes++;}
       }
       int alice = 0, bob = 0;
       while(zeroes > 0){
            if(count==1 || count==3){
                alice++; zeroes--;
            }else if(count==4 || count==6){
                bob++; zeroes--;
            }
            count++;
            if(count==7){
                count = 1;
            }

       }
    //    cout<<alice<<" "<<bob<<endl;
       if(alice > bob){
        cout<<"BOB"<<endl;
       }else if(alice < bob){
        cout<<"ALICE"<<endl;
       }else{
        cout<<"DRAW"<<endl;
       }
    }
    return 0;
}