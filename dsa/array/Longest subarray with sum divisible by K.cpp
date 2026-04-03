// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& a, int k) {
            map<int,int> m;
            m[0] = -1;
            int s = 0;
            int ans = INT_MIN;
            int n = a.size();
            for(int i = 0; i < n; i++){
                s+=a[i];
                int c = s%k;
                if(c < 0){
                    c = ((s%k)+k);
                }
                if(m.find(c) != m.end()){
                    ans = max(ans, i - m[c]);
                }else{
                    m[c] = i;
                }
                s = c;
            }
            if(ans==INT_MIN)ans = 0;
            return ans;
    }
};