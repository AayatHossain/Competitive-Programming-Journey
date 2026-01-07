#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        int fl = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i]==0){
                fl=1;
            }
        }

        set<int> m;
        for(int i = 0; i <= k; i++){
            m.insert(i);
        }
        vector<int> f(k+1,0);
        int ans = INT_MIN;

        unordered_map<int,int> freqAll;
        int dupAll = 0;
        int dupK = 0;

        for(int i = 0; i < n; i++){
            freqAll[a[i]]++;
            if(freqAll[a[i]]==2){
                dupAll++;
            }

            if(a[i] <= k){
                if(f[a[i]]==0){
                    m.erase(a[i]);
                }
                if(a[i] < k && f[a[i]]==1){
                    dupK++;
                }
                f[a[i]]++;
            }

            if(i >= k-1){
                int mex = *m.begin();

                if(mex < k){
                    ans = max(ans, mex);
                }else{
                    if(dupK > 0){
                        ans = max(ans, k);
                    }else{
                        ans = max(ans, k-1);
                    }
                }

                int out = a[i-k+1];

                if(freqAll[out]==2){
                    dupAll--;
                }
                freqAll[out]--;
                if(freqAll[out]==0){
                    freqAll.erase(out);
                }

                if(out <=k){
                    if(out < k && f[out]==2){
                        dupK--;
                    }
                    f[out]--;
                    if(f[out]==0){
                        m.insert(out);
                    }
                }
            }
        }

        if(!fl){
            ans = 0;
        }else{
            ans = max(1,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
