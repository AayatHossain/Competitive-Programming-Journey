class Solution {
  public:
    static bool cmp(string s, string t){
        string v1 = s+t;
        string v2 = t+s;
        return v1 > v2;
    }
  
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> a(arr.size());
        for(int i = 0; i < arr.size(); i++){
            a[i] = to_string(arr[i]);
        }
        sort(a.begin(),a.end(),cmp);
        if(a[0]=="0")return "0";
        string s = "";
        for(int i= 0;i < arr.size(); i++){
            s+=a[i];
        }
        return s;
    }
};