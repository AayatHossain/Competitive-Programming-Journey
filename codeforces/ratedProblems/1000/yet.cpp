#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> s;
        cout<<1<<" ";
        for(int i = 2; i <= n; i++){
            int val = i;
            if(s.find(val) == s.end()){
                cout<<val<<" ";
                s.insert(val);
                val = val + val;
                while(val <= n){
                    if(s.find(val) == s.end()){
                        cout<<val<<" ";
                        s.insert(val);
                    }
                    val = val + val;
                }

            }
            
        }
        cout<<endl;
    }
    return 0;
}