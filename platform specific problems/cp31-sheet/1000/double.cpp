#include<bits/stdc++.h>
using namespace std;
int findSubStr(string large, string s, string small){
    int i = 0, j = s.size()-1;
    while(j < large.size()){
        string temp;
        for(int k = i; k <= j; k++){
            temp+= large[k];
        }
        // cout<<s<<" "<<temp<<endl;
        if(s==temp){
            int moves1 = large.size() - s.size();
            int moves2 = small.size() - s.size();
            return moves1+moves2;
        }
        i++;j++;
    }
    return INT_MAX;
}
int main(){
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        string small,large;
        if(a.size() < b.size()){
            small = a;
        }else{
            small = b;
        }
        if(small==a){
            large = b;
        }else{
            large = a;
        }
        int ans = INT_MAX;
        for(int i = 0; i < small.size(); i++){
            string s;
            for(int j = i; j < small.size(); j++){
                s+=small[j];
                ans = min(ans, findSubStr(large,s, small));
            }
        }
        if(ans == INT_MAX){
            cout<<a.size() + b.size()<<endl;
        }else{
            cout<<ans<<endl;

        }
    }
    return 0;
}