#include<bits/stdc++.h>
using namespace std;
int main(){
    
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> m;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            m[i]++;
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(m[i] > m[i-1]){
                count+= m[i] - m[i-1];
            }
        }
        cout<<count<<endl;
    }
    return 0;
}