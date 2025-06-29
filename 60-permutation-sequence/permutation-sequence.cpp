class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;

        for(int i = 1; i<=n; i++){
            vec.push_back(i);
        }

        // Need k-1 calls since we start with 1st permutation
        for(int i = 0; i < k-1; i++){
            next_permutation(vec.begin(), vec.end());
        }
        
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += to_string(vec[i]);  // Fixed: convert int to string
        }
        
        return ans;
    }
};