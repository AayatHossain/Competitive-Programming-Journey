#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int w,h,a,b;cin>>w>>h>>a>>b;
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        int xf = x1+a;
        int yf = y1+b;
        int horizontal = x2 - xf;
        int vertical = abs(y2 - yf);
        if(y1==y2)
        int flag = 0;
        if(horizontal%a==0 || vertical%b==0){
            flag = 1;
        }
        
        cout<<xf<<" "<<yf<<endl;
        cout<<horizontal<<" "<<vertical<<endl;
        cout<<a<<" "<<b<<endl;
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}