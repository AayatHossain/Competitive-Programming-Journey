#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    if(sum & 1){
        cout<<"NO"<<endl;
    }else{
        int half = sum / 2;
        set<int> s1;
        set<int> s2;
        int m = n;
        while(half > 0){
            if(half - m < 0){
                m = half;
            }
            s1.insert(m);
            half -= m;
            m--;
        }
        for(int i = 1; i <= n; i++){
            if(s1.find(i) == s1.end()){
                s2.insert(i);
            }
        }
        cout<<"YES"<<endl;
        cout<<s1.size()<<endl;
        for(auto x: s1){
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<s2.size()<<endl;
        for(auto x: s2){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}