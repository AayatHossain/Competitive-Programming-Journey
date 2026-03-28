class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int n = a.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n-2; i++){
            if(i > 0 && a[i]==a[i-1])continue;
            int s = -a[i];
            int j = i+1, k = n-1;
            while(j < k){
                if(a[j]+a[k] < s){
                    j++;
                }else if(a[j]+a[k] > s){
                    k--;
                }else{
                    vector<int> b = {a[i],a[j],a[k]};
                    ans.push_back(b);
                    j++;k--;
                    while(j < k && a[j]==a[j-1])j++;
                    while(j < k && a[k]==a[k+1])k--;
                }
            }
        }
        
        return ans;
    }
};