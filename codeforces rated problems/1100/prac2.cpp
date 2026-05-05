#include<bits/stdc++.h>
using namespace std;
signed main(){
    int a = 'a';
    int b = 'b';
    int c = 'c';
    cout<<char(((a^b)^(a^b))^c)<<endl;
    return 0;
}