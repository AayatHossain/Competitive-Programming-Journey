class Solution {
  public:
    int majorityElement(vector<int>& a) {
        // code here
        int n = a.size();
        int cand = a[0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(a[i]==cand){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt==0){
                cnt = 1;
                cand = a[i];
            }
        }
        cnt = 0;
        for(int x: a){
            if(x==cand){
                cnt++;
            }
        }
        if(cnt > n/2)return cand;
        return -1;
        
    }
};