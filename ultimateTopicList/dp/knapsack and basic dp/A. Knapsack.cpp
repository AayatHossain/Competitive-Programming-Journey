#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5;
int n,w;
vector<int> a;
signed main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>w;
        a.resize(n);
        for(int i = 0; i < n; i++)cin>>a[i];
        int f = 0;
        set<int> ans;
        for(int i = 0; i < n; i++){
            if(a[i] >= ceil(w/2.0) && a[i] <= w){
                f=1;
                ans.insert(i+1);break;

            }
        }
        if(!f){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum+=a[i];
                if(sum < ceil(w/2.0)){
                    ans.insert(i+1);
                }
                else if(sum >= ceil(w/2.0) && sum <= w){
                    f=1;
                    ans.insert(i+1);
                    break;

                }else{
                    sum-=a[i];
                }
                
            }
        }
        if(f){
            cout<<ans.size()<<endl;
            for(auto x: ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}