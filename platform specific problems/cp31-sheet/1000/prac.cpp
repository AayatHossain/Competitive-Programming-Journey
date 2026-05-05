#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the top 3 indices with the highest values
vector<int> get_best3(const vector<int>& arr) {
    vector<int> indices(arr.size());
    for(int i = 0; i < arr.size(); i++){
        indices[i] = i;
    } // Initialize with first three indices
    // Sort indices based on the values in the array in descending order
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return arr[i] > arr[j];
    });
    return {indices[0], indices[1], indices[2]}; // Return top 3 indices
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the arrays
        vector<int> a(n), b(n), c(n);
        
        // Input arrays a, b, and c
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        
        // Get the top 3 indices for each array
        vector<int> best_a = get_best3(a);
        for(int i = 0; i < 3; i++){
            cout<<best_a[i]<<" ";
        }
        cout<<endl;
        vector<int> best_b = get_best3(b);
        vector<int> best_c = get_best3(c);
        
        int ans = 0;
        // Iterate through all combinations of top 3 indices
        for (int x : best_a) {
            for (int y : best_b) {
                for (int z : best_c) {
                    // Ensure all indices are unique
                    if (x != y && x != z && y != z) {
                        ans = max(ans, a[x] + b[y] + c[z]);
                    }
                }
            }
        }
        
        cout << ans << endl; // Print the result
    }
    return 0;
}