https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

ON AND O1. ZERO COUNT METHOD.
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& a) {
        // code here
        int n = a.size();
        int pos = -1;
        int cnt = 0;
        int p = 1;
        for(int i = 0; i < n; i++){
            if(a[i]==0){
                cnt++;
                pos = i;
            }
            if(a[i]!=0){
                p*=a[i];
            }
        }
        if(cnt >= 2){
            for(int i = 0; i < n; i++)a[i]=0;
        }else if(cnt==1){
            a[pos] = p;
            for(int i = 0; i < n; i++){
                if(i!=pos)a[i]=0;
            }
        }else{
            for(int i = 0; i < n; i++){
                a[i] = p/a[i];
            }
        }
        return a;
    }
};
