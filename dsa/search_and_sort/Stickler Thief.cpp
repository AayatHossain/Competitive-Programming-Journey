class Solution {
  public:
    int findMaxSum(vector<int>& a) {
        // code here
        int n = a.size();
        if(n > 1){
            a[1] = max(a[0],a[1]);
        }
        for(int i = 2; i < n; i++){
            int v1 = a[i-1];
            int v2 = a[i-2];
            a[i] = max(a[i] + v2, v1);
        }
        return a[n-1];
    }
};