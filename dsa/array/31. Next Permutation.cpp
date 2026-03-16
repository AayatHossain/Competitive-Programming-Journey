//ON time and O1 space. MY SOLUTION

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i1 = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                i1 = i;
                break;
            }
        }
        int i2 = -1;
        if (i1 != -1) {
            int mx = INT_MAX;
            for (int i = n-1; i >= i1+1; i--) {
                if (a[i] > a[i1] && a[i] < mx) {
                    mx = a[i];
                    i2 = i;
                }
            }
        }

        if (i1 != -1 && i2 != -1) {
            int temp = a[i1];
            a[i1] = a[i2];
            a[i2] = temp;
        }

        int i = i1 + 1;
        int j = n - 1;
        while (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
};



//CLEANER IMPLEMENTATION BY GPT

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int i = n - 2;

        // 1. Find pivot
        while (i >= 0 && a[i] >= a[i + 1]) {
            i--;
        }

        // 2. Find element just larger than pivot
        if (i >= 0) {
            int j = n - 1;
            while (a[j] <= a[i]) {
                j--;
            }
            swap(a[i], a[j]);
        }

        // 3. Reverse suffix
        reverse(a.begin() + i + 1, a.end());
    }
};