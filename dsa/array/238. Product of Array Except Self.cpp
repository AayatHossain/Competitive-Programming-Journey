//MULTIPLE SOLUTIONS.

//MY SOLUTION 1. TIME AND SPACE = O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> p(n);
        vector<int> s(n);
        p[0]=a[0];
        for(int i = 1; i < n; i++){
            p[i] = p[i-1] * a[i];
        }
        s[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--){
            s[i] = s[i+1]*a[i];
        }
        vector<int> ans;
        ans.push_back(s[1]);
        for(int i = 1; i < n-1; i++){
            ans.push_back(p[i-1]*s[i+1]);

        }
        ans.push_back(p[n-2]);
        return ans;
    }
};




//My SOLUTION 2: TIME = O(N) AND SPACE = O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        ans[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--){
            ans[i] = ans[i+1]*a[i];
        }
        int p = a[0];
        ans[0] = ans[1];
        for(int i = 1; i < n-1; i++){
            ans[i] = ans[i+1]*p;
            p *= a[i];
        }
        ans[n-1] = p;
        return ans;
    }
};



//GPT SOLUTION BIG ON AND BIG O1 KINDA SAME AS SOLUTION 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        int p = 1;
        for(int i = 0; i < n; i++){
            ans[i] = p;
            p *= a[i];
        }
        int s = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i]*=s;
            s*=a[i];
        }
        return ans;
    }
};



// SOLUTION IF DIVISION IS ALLOWED, BIG ON AND BIG O1

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,0);
        int prod = 1;
        int z = 0;
        int zi = -1;
        for(int i = 0; i < n; i++){
            if(a[i]==0){
                z++;
                zi = i;
            }else{  
                prod*=a[i];
            }
        }

        if(z==1){
            ans[zi]=prod;
        }else if(z==0){
            for(int i = 0; i < n; i++){
                ans[i] = prod/a[i];
            }
        }
        
        return ans;
    }
};
