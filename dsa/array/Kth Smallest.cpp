class Solution {
  public:
    int kthSmallest(vector<int> &a, int k) {
        // code here
        priority_queue<int> q;
        for(int i = 0; i < a.size(); i++){
            q.push(a[i]);
            if(q.size() > k)q.pop();
        }
        return q.top();
    }
};