class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;
        
        while (right < n) {
            // Expand window by adding right element
            sum += nums[right];
            
            // Contract window from left while sum >= target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};