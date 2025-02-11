#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int main(){
    
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<int> a(n);
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            m[a[i]].push_back(i);
        }
        
        
    }
    return 0;
}