class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int n = arr[i];
            if (binary_search(arr.begin(), arr.begin() + i, 2 * n) || 
                binary_search(arr.begin() + i + 1, arr.end(), 2 * n)) {
                return true;
            }
        }
        return false;
    }
};
