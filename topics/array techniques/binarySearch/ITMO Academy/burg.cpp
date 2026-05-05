#include<bits/stdc++.h>
using namespace std;
#define int long long

int ok(int x, vector<int> &ing, vector<int> & price, int b, int s, int c, int money){
    int fB = b*x;
    int fS = s*x;
    int fC = c*x;

    int eB = 0, eS = 0, eC = 0;
    if(fB -ing[0] > 0){
        eB = fB - ing[0];
    }
    if(fS -ing[1] > 0){
        eS = fS - ing[1];
    }
    if(fC -ing[2] > 0){
        eC = fC - ing[2];
    }
    //  eB = fB - b;
    //  eS = fS - s;
    //  eC = fC - c;

    int spent = (eB*price[0] + eS*price[1] + eC*price[2]);
    // money -= spent;
    
    return spent <= money;
}

signed main(){
    string t;vector<int>ing(3), price(3);
    int balance;
    cin>>t;
    for(int i = 0; i < 3; i++){
        cin>>ing[i];
    }
    for(int i = 0; i < 3; i++){
        cin>>price[i];
    }
    cin>>balance;
    int b = 0, s = 0, c = 0;
    for(int i = 0; i < t.size(); i++){
        if(t[i]=='B'){
            b++;
        }else if(t[i]=='S'){
            s++;
        }else{
            c++;
        }
    }
    int l = 0, r = 1e13;
    int mid;
    while(r > l+1){
        mid = l + (r-l)/2;
        if(ok(mid, ing,price,b,s,c,balance)){
            // cout<<l<<" "<<mid<<endl;
            l = mid;
        }else{
            r = mid;
        }
    }
    cout<<l<<endl;


    
    return 0;
}