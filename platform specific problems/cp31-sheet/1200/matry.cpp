#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        map<int, int> m;
        set<int> s;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            s.insert(x);
            s.insert(x+1);
            m[x]++;
            
            
        }
        int count = 0;
        int prev = 0;
        for(auto x: s){
           if(m[x] > m[prev]){
            count += m[x] - m[prev];
           }
           prev = x;

        }
        cout<<count<<endl;
    }
    return 0;
}