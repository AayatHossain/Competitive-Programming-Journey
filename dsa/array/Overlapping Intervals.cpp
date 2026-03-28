class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        ans.push_back(a[0]);
        // int index = 0;
        for(int i = 1; i < n; i++){
            int pl = ans[ans.size()-1][0];
            int pr = ans[ans.size()-1][1];
            int cl = a[i][0];
            int cr = a[i][1];
            if(cl <= pr){
                vector<int> b;
                b.push_back(pl);
                b.push_back(max(pr,cr));
                ans.pop_back();
                ans.push_back(b);
            }else{
                vector<int> b;
                b.push_back(cl);
                b.push_back(cr);
                ans.push_back(b);
            }
        }
        return ans;
        
    }
};