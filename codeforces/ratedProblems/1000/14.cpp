
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int count1 = 1,count2 = 1, count3 = 0;
        for(int i = 0; i < n-1; i++){
            if(a[i]==a[i+1]){
                count1++;
            }else{
                break;
            }
        }
        for(int i = n-1; i >= 0; i--){
            if(a[i]==a[i-1]){
                count2++;
            }else{
                break;
            }
        }
        int i = 0;
        int j = n-1;
        while(i < j){
            if(a[i]==a[j]){
                count3 += 2;
            }else{
               
                if(a[i]==a[i-1]){
                   
                    while(a[i] == a[i-1]){
                        count3++;
                        i++;
                    }
                }
                if(a[j]==a[j+1]){
                  
                    while(a[j] == a[j+1]){
                        count3++;
                        j--;
                    }
                }
                break;
            }
            i++;
            j--;
        }
        
        int ans1 = n - count1;
        int ans2 = n - count2;
        int ans3 = n - count3;
        if(ans1==-1){
            ans1 = 0;
        }
        if(ans2==-1){
            ans2 = 0;
        }
        if(ans3==-1){
            ans3 = 0;
        }

        cout<<min(ans1,min(ans2, ans3))<<endl;
    }
        
    return 0;
}