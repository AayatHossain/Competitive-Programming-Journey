#include<bits/stdc++.h>
using namespace std;
signed main(){
    int z,o; cin>>z>>o;
    int total = z+o;
    int g = 3;
    int f = 1;
    
    // if(z > 1 && g < 2){
    //     f = 0;
    // }
    // if(z > 1 && g > 3){
    //     f = 0;
    // }
    vector<int> ans(total+1,-1);
    // cout<<g<<endl;
    int s = -1;
    if(o==1 || z==o){
        s = 2;
        g = 2;
    }else{
        s = 3;
    }
    int index = -1;

    for(int i = s; i <= total; i+=g){
        if(z==0){
            break;
        }else{
            ans[i] = 0;
            index = i;
            z--;

        }
    }
    // if(z > 0){
    //     f = 0;
    // }
    if(total - index > 2 || z > 0){
        f = 0;
    }
    for(int i = 1; i <= total && f; i++){
            if(ans[i] != 0){
                ans[i] = 1;
            }
    }
    if(f){
        for(int i = 1; i <= total; i++){
            cout<<ans[i];
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}