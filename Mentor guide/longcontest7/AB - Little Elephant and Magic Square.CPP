#include<bits/stdc++.h>
using namespace std;
signed main(){
    int a[3][3];
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            cin>>a[i][j];
        }
    }
    // int y = ((a[0][1]+a[0][2])+(a[2][0]+a[2][1])-(a[1][0]+a[1][2]))/2;
    // int x = a[2][0] + a[2][1] - y;
    // int z = a[0][1]+a[0][2] -y;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         if(i==0 && j==0){
    //             cout<<x<<" ";
    //         }else if(i==1 && j==1){
    //             cout<<y<<" ";
    //         }else if(i==2 && j == 2){
    //             cout<<z<<" ";
    //         }else{
    //             cout<<a[i][j]<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    int x,y,z;
    for(int i  = 1; i <= 100000;i++){
        int x = i;
        int sum = a[0][1]+a[0][2]+x;
        int z = sum - (a[0][2]+a[1][2]);
        int y = sum - (a[0][1] + a[2][1]);
        if(y>0 && z>0 && x+y+z==sum){
            a[0][0] = x;
            a[1][1] = y;
            a[2][2] = z;
            break;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<a[i][j]<<" ";
        }

        cout<<endl;
    }
    return 0;
}