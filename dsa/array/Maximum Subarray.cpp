class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr = 0;
        for(int i = 0; i < (int)nums.size();i++){
            curr+=nums[i];
            if(curr < 0){
                curr = 0; continue;
            }
            ans = max(ans,curr);
        }
        if(ans==INT_MIN){
            
            for(int i = 0; i < (int)nums.size();i++){
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};