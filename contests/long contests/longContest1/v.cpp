#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;cin>>n>>q;
    queue<pair<string,int>> qu;
    for(int i = 0; i < n; i++){
        string s; int t; cin>>s>>t;
        qu.push(make_pair(s,t));
    } 
    int curr = 0;
    while(!qu.empty()){
        pair<string, int> p = qu.front();
        qu.pop();
        if(p.second > q){
            int newTime = p.second - q;
            qu.push(make_pair(p.first,newTime));
            curr += q;
        }else{
            curr += p.second;
            cout<<p.first<<" "<< curr<<endl;
        }
        
    }
    return 0;
}