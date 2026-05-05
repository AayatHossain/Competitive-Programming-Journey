#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSquare(vector<vector<int>>& a) {
        // code here
        int n = a.size();
        int m = a[0].size();
        int mx = INT_MIN;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
               if(a[i][j]!=0){
                    int d,u,l;
                    d = a[i-1][j-1];
                    u = a[i-1][j];
                    l = a[i][j-1];
                    if(d==u&&u==l){
                        a[i][j]=d+1;
                    }else{
                        a[i][j]=min(d,min(u,l))+1;
                    }
                    mx=max(mx,a[i][j]);
               }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
        if(mx==INT_MIN)mx=0;
        return mx;
    }
};

int main() {
    Solution sol;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    
    int result = sol.maxSquare(a);
    cout << "Result:  " << result << endl;
    
    return 0;
}