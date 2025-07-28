class Solution {
public:
    int maxOr = 0;
    int count = 0;
    
    void solve(vector<int>& nums, int idx, int currentOr) {
        if(idx == nums.size()) {
            if(currentOr > maxOr) {
                maxOr = currentOr;
                count = 1;
            } else if(currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        // Include current element
        solve(nums, idx + 1, currentOr | nums[idx]);
        
        // Exclude current element
        solve(nums, idx + 1, currentOr);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        solve(nums, 0, 0);
        return count;
    }
};
