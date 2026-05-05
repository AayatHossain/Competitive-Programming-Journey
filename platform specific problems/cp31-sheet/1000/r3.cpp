// https://codeforces.com/problemset/problem/1800/B

#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vector<int> lc(26);
        vector<int> uc(26);
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c < 97){//uc
                uc[c - 'A']++;
            }else{
                lc[c - 'a']++;
            }
        }
        int pairs = 0;
        for(int i = 0; i < 26; i++){
            int minVal = min(lc[i], uc[i]);
            pairs += minVal;
            lc[i] -= minVal;
            uc[i] -= minVal;
            if(k > 0){
                if(lc[i] > 0){
                    int extraPairs = lc[i] / 2;
                    if(k > extraPairs){
                        pairs += extraPairs;
                        k -= extraPairs;
                    }else{
                        pairs += k;
                        k = 0;
                    }
                }else if(uc[i] > 0){
                    int extraPairs = uc[i] / 2;
                    if(k > extraPairs){
                        pairs += extraPairs;
                        k -= extraPairs;
                    }else{
                        pairs += k;
                        k = 0;
                    }
                }
            }
        }
        cout<<pairs<<endl;
    }
}