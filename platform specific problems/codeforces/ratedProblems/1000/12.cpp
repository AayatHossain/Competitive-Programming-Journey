// https://codeforces.com/problemset/problem/1955/B
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c,d;
        cin>>n>>c>>d;
        vector<int> a(n*n);
        for(int i = 0; i < n*n; i++){
            
                cin>>a[i];
            
        }
        sort(a.begin(), a.end());
        vector<vector<int>> square(n, vector<int>(n));
        square[0][0] = a[0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i+1 < n){
                    square[i+1][j] = square[i][j] + c;
                }
                if(j+1 < n){
                    square[i][j+1] = square[i][j] + d;
                }
            }
        }
        vector<int> ans(n*n);

        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[k] = square[i][j];
                k++;
            }
          
        }
        sort(ans.begin(), ans.end());
       
        if(ans==a){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}