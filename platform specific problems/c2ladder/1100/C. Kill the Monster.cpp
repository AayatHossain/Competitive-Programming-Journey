#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int ch,cd,mh,md,k,w,a;
        cin>>ch>>cd>>mh>>md>>k>>w>>a;
        int f = 0;
        for(int i = k; i >= 0; i--){
            int weapon = i;
            int health = k-weapon;
            int nch = ch + a*health;
            int ncd= cd + w*weapon;
            int m2 = ceil((double)nch/md);
            int m1 = ceil((double)mh/ncd);
            // cout<<nch<<" "<<ncd<<endl;
            // cout<<m1<<" "<<m2<<endl;
            if(m1 <= m2){
                f = 1;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}