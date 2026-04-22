ONLOGN AND ON
class Solution {
  public:
    vector<double> getMedian(vector<int> &a) {
        // code here
       int n = a.size();
       vector<double> res;
       priority_queue<int> maxh;
       priority_queue<int,vector<int>,greater<int>> minh;
       for(int i = 0; i < n; i++){
           maxh.push(a[i]);
           
           int v = maxh.top();
           maxh.pop();
           minh.push(v);
           
           if(maxh.size() < minh.size()){
               v = minh.top();
               minh.pop();
               maxh.push(v);
           }
           if(i&1){
               res.push_back((maxh.top()+minh.top())/2.0);
           }else{
               res.push_back(maxh.top());
           }
       }
       return res;
        
        
    }
};
