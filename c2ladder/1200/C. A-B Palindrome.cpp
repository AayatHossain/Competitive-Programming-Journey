#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        string s; cin>>s;
        int n = s.size();
        int f = 1;
        int lim;
        if(n&1){
            lim = n/2 + 1;
        }else{
            lim = n/2;
        }
        for(int i = 0; i < lim; i++){

            int i1 = i;
            int i2 = n - i - 1;

            if(i1==i2){
                if(s[i1]=='1')b--;
                if(s[i1]=='0')a--;
            }else{
                
                char c1 = s[i1];
                char c2 = s[i2];
                if(c1=='1' && c2=='1'){b-=2;}
                if(c1=='0' && c2=='0'){a-=2;}
                if(c1=='1' && c2=='?'){b-=2;s[i2]='1';}
                if(c1=='?' && c2=='1'){b-=2;s[i1] = '1';}
                if(c1=='?' && c2=='0'){a-=2;s[i1] = '0';}
                if(c1=='0' && c2=='?'){a-=2;s[i2] = '0';}
                if(c1=='1' && c2=='0'){f = 0; break;}
                if(c1=='0' && c2=='1'){f = 0; break;}
            }
        }
        if(!f || a < 0 || b < 0){
            cout<<-1<<endl;
        }else{
            for(int i = 0; i < lim; i++){
                char c1 = s[i];
                char c2 = s[n-i-1];
                if(c1=='?' && c2=='?'){
                    if(i==n-i-1){
                        if(a==0 && b == 0){
                            f = 0;
                            break;
                        }else if(a > b){
                            s[i] = '0';
                        }else{
                            s[i] = '1';
                        }
                    }else{
                        if(a>=b && a>=2){
                            s[i] = '0';
                            s[n-i-1] = '0';
                            a-=2;
                        }else if(b > a && b>=2){
                            s[i] = '1';
                            s[n-i-1] = '1';
                            b-=2;
                        }else{
                            f = 0;
                            break;
                        }
                    }
                }
            }
            if(!f){
                cout<<-1<<endl;
            }else{
                cout<<s<<endl;
            }
        }
        // cout<<a<<" "<<b<<endl;
        // cout<<s<<endl;
    }
    return 0;
}