https://leetcode.com/problems/4sum/

ON^3 AND O1.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i = 0; i < n-3; i++){
            if(i > 0 && a[i]==a[i-1])continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && a[j]==a[j-1])continue;
                int k = j+1, l = n-1;
                while(k < l){
                    long long s = (long long)a[i]+a[j]+a[k]+a[l];
                    if(s < t){
                        k++;
                    }else if(s > t){
                        l--;
                    }else{
                        ans.push_back({a[i],a[j],a[k],a[l]});
                        k++; l--;
                        while(k < l && a[k]==a[k-1])k++;
                        while(k < l && a[l]==a[l+1])l--;
                    }
                }
            }
            
        }
        return ans;
    }
};