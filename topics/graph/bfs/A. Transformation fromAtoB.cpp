#include<bits/stdc++.h>
using namespace std;
vector<int> p;
// int f(int a, int b){
//     if(a>b){
//         return 0;
//     }
//     if(a==b){
//         p.push_back(b); return 1;
//     }

//     if(b%2){
//         int v1 = f(a,b/10);
//         if(v1){
//             p.push_back(b);
//         }
//         return v1;
//     }
//     int v2 = f(10*a+1,b);
//     if(v2){
//         p.push_back(a);
//         return 1;
//     }
//     return 0;
// }
signed main(){
    int a, b; cin>>a>>b;
    // int ans = f(a,b);

    p.push_back(b);
    while(b > a){
        if(b%10==1){
            b/=10;
            p.push_back(b);
        }else if(b%2==0){
            b/=2;
            p.push_back(b);
        }else{
            break;
        }
        // cout<<b<<endl;
    }

    if(b==a){
        cout<<"YES"<<endl;
        cout<<p.size()<<endl;
        reverse(p.begin(),p.end());
        for(auto x: p){
            cout<<x<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}