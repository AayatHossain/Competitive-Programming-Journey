#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
      int n; char c;
      string s;
      cin>>n>>c;
      cin>>s;
      s = s+s;
      int ans = -1;
      for(int i = 0; i < s.size(); i++){
        if(s[i]==c){
            int j = i;
            while(j < s.size()-1 && s[j] != 'g'){
                j++;
            }
            if(s[j]=='g'){
                ans = max(ans, j-i);
            }
            i = j;
        }
      }
      cout<<ans<<endl;
    }
    return 0;
}