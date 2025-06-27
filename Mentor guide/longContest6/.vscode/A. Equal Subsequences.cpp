    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    signed main(){
        int t;cin>>t;
        while(t--){
            int n,k;cin>>n>>k;
            string s;
            if(n - 2 < k || k == 0){
                for(int i = 0; i < n; i++){
                    if(k > 0){
                        s+='1';
                        k--;
                    }else{
                        s+='0';
                    }
                }
            }else{
                for(int i = 0; i < n; i++){
                if(i==0){s+='0';continue;}
                if(i==n-1){s+='1';continue;}
                if(k>1){
                    s+='1';k--;
                }else{
                    s+='0';
                }
            
            }
            }
            reverse(s.begin(), s.end());
            cout<<s<<endl;
        }
    }