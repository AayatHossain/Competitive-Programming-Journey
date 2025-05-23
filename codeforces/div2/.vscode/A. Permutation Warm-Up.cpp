#include<bits/stdc++.h>
using namespace std;
#define SPEEDY std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int c = 1;
        int sum = 0;
        for(int i = n; i>=1; i--){
            sum += abs(i-c);
            c++;
        }
        cout<<sum/2 + 1<<endl;
    }
    return 0;
}