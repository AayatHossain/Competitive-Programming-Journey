n1+n2+n3 and 1
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int m = a.size();
        int n = b.size();
        int o = c.size();
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while(i < m && j < n && k < o){
            if(a[i]==b[j] && b[j]==c[k]){
                if(res.size() > 0 && res[res.size()-1] != a[i]){
                    res.push_back(a[i]);
                }else if(res.size()==0){
                    res.push_back(a[i]);
                }
                i++;j++;k++;
            }
            else if(b[j] < a[i])j++;
            else if(c[k] < a[i])k++;
            else i++;
        }
        return res;
    }
};