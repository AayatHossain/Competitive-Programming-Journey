#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>a[i][j];
            }
        }
        int moves = 0;
        
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                int c1 = a[i][j];
                int c2 = a[n-i-1][n-j-1];
                if(c1 != c2){
                    moves++;
                }
                
                // cout<<c1<<" "<<c2<<endl;
            }
        }
        if(n % 2 != 0){
            int i = n/2;
            for(int j = 0; j < n/2; j++){
                int c1 = a[i][j];
                int c2 = a[n-i-1][n-j-1];
                if(c1 != c2){
                    moves++;
                }
            }
        }
        // cout<<moves<<endl;
        if(moves > k){
            cout<<"NO"<<endl;
        }else if(moves == k){
            cout<<"YES"<<endl;
        }else if(moves < k){
            int extra = k - moves;
            if(n % 2 == 0){
                if(extra % 2 == 0){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }else{
                cout<<"YES"<<endl;
            }
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}