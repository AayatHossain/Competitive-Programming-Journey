//ON AND O1 SOLUTION WITH XOR
class Solution {
  public:
    vector<int> twoOddNum(vector<int>& a) {
        int n = a.size();
        vector<int> ans(2,0);
        unsigned int x = 0;
        for(int i = 0; i < n; i++){
            x^=a[i];
        }

        x = (x&(-x));

        for(int i = 0; i < n; i++){
            if(a[i] & x){
                ans[1] ^= a[i];
            }else{
                ans[0] ^= a[i];
            }
        }
        if(ans[0] < ans[1]){
            swap(ans[0],ans[1]);
        }
        return ans;
    }
};