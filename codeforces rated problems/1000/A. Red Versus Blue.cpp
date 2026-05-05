#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,a,b; cin>>n>>a>>b;
        int v = a/(b+1);
        int w = a%(b+1);

        int c = 1;
        int j = -1;
        while(w > 0){
            for(int i = 0; i < v; i++){
                cout<<"R";
                j++;
            }
            cout<<"RB";
            w--;
            j+=2;
        }
        for(int i = j+1; i<n; i++){
            if(c<=v){
                cout<<"R";
                c++;
            }else{
                cout<<"B";
                c=1;
            }
        }
        cout<<endl;
    }
    return 0;
}