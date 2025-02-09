// https://codeforces.com/problemset/problem/1969/B

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long total = 0;
        long long fixedIndx = -1;
        for(long long i = 0; i < s.size(); i++){
            if(s[i]=='1'){
                    long long count = 0;
                    if(fixedIndx < i){
                        fixedIndx=i;
                    }

                for(long long j = fixedIndx; j < s.size(); j++){
                    if(s[j]=='1'){
                        count++;
                        if(j==s.size()- 1 && s[j]=='1'){
                            break;
                        }
                    }else{
                        count++;
                      
                        total += j-i+1;
                        s[j] = '1';
                        s[i] = '0';
                       fixedIndx = j+1;
                        break;
                    }
                }
            }
        }
        cout<<total<<endl;
       

    }
    return  0;
}