class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOps, int m) {
        if (m == 0) return false;
        int totalOps = 0;
        for (int &num : nums) {
            totalOps += (num - 1) / m;
            if (totalOps > maxOps) return false; 
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1; 
        int r = *max_element(begin(nums), end(nums));
        int res = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
