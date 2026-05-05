#include<bits/stdc++.h>
using namespace std;
#define int long long
bool present(string target, string s){
    int i = 0, j = target.size() - 1;
    while(j < s.size()){
        string temp;
        for(int k = i; k <= j; k++){
            temp+=s[k];
        }
        if(temp==target){
            return true;
        }else{
            i++;j++;
        }
    }
    return false;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int found = 0;
        int n;cin>>n;string s;cin>>s;
        for(char c = 'a'; c <= 'z'; c++){
            string str;
            str += c;
            if(!present(str,s)){
                cout<<str<<endl;
                found = 1;
                break;
            }
        }
        for(char c = 'a'; c <= 'z' && !found; c++){
            for(int d = 'a'; d <= 'z'; d++){
                string str; str+=c; str+=d;
                if(!present(str,s)){
                    cout<<str<<endl;
                    found = 1;
                    break;
                }
            }
        }
        for(char c = 'a'; c <= 'z' && !found; c++){
            for(int d = 'a'; d <= 'z' && !found; d++){
                for(int e = 'a'; e<='z'; e++){
                    string str; str+=c; str+=d; str+=e;
                    if(!present(str,s)){
                        cout<<str<<endl;
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}