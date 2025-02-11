#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int main(){
    
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        vector<int> a(n);
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m[a[i]].push_back(i);
        }
        for(auto x: m){
            int key = x.first;
            vector<int> val = x.second;
            cout<<key<<end;
            for(auto y: val){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}