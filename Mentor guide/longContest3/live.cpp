#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin>>n;
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x % 3 == 0){c0++;}
            if(x % 3 == 1){c1++;}
            if(x % 3 == 2){c2++;}
        }
        int curr = 0;
        int moves = 0;
        while(c0 != c1 || c1 != c2){
            if(curr==0){ if(c0 > n/3) {moves += (c0 - n/3); c1+= (c0 - n/3); c0 -= (c0 - n/3);  }curr = 1; }
            if(curr==1){ if(c1 > n/3) {moves += (c1 - n/3); c2+= (c1 - n/3); c1 -= (c1 - n/3); } curr = 2;}
            if(curr==2){ if(c2 > n/3) {moves += (c2 - n/3); c0+= (c2 - n/3); c2 -= (c2 - n/3); } curr = 0;}
            // cout<<c0<<" "<<c1<<" "<<c2<<endl;
        }
        cout<<moves<<endl;
            
    }
}