#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

      
        unordered_map<long long, long long> um;

        for(long long i = 0; i < n; i++){
            int x;
            cin>>x;
            um[x] = i;
        }
      
        long long start = 0;
        long long end = n-1;
        long long max = n;
        long long min = 1;
        long long flag = 0;
        while(start < end){
            
            
            long long maxI = um[max];
            long long minI = um[min];

            long long startChanged = 0;
            long long endChanged = 0;
            
            if(maxI==start){
                start++;
                startChanged = 1;
                max--;
            }
            if(maxI==end){
                end--;
                endChanged = 1;
                max--;
            }
            if(minI==start){
                start++;
                startChanged = 1;
                min++;
            }
            if(minI==end){
                end--;
                endChanged = 1;
                min++;
            }
           
       
            if(startChanged==0 && endChanged==0){
                cout<<start+1<<" "<<end+1<<endl;
                flag = 1;
                break;
            }
            
        }
        if(!flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}