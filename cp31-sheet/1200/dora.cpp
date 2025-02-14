#include<bits/stdc++.h>
using namespace std;

long long bS(long long s, long long e, vector<pair<long long,long long>> b, long long v){
    long long mid;
    while(s <= e){
        mid = (s+e)/2;
        if(b[mid].first == v){
            return b[mid].second;
        }else if(b[mid].first < v){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return - 1;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        // vector<pair<long long,long long>> b;
        unordered_map<long long, long long> um;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            // b.push_back(make_pair(a[i], i));
            um[a[i]] = i;
        }
        // sort(b.begin(), b.end());
        long long start = 0;
        long long end = n-1;
        long long max = n;
        long long min = 1;
        long long flag = 0;
        while(start < end){
            
            // cout<<max<<" "<<min<<endl;
            // cout<<start<<" "<<end<<endl;

            // long long maxI = bS(0, n-1, b,max);
            // long long minI = bS(0, n-1, b, min);
            long long maxI = um[max];
            long long minI = um[min];

            
            
            // cout<<maxI<<" "<<minI<<endl;
            // cout<<"zzzzzzzzzzzzzz"<<endl;
            // if(maxI==-1 || minI== -1){
            //     cout<<"hi";
            // }


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
           
            // cout<<start<<" "<<end<<"with max and min = "<<max<<" "<<min<<endl;
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