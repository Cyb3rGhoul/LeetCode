class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = nums[0];
        int maxSum = nums[0];

        int currMin = nums[0];
        int currMax = nums[0];

        for(int i = 1; i<n; i++){
            currMin = min(nums[i] , nums[i]+currMin);
            minSum = min(currMin,minSum);
            currMax = max(nums[i]  , nums[i]+currMax);
            maxSum = max(currMax,maxSum);
        }

        return max(maxSum, abs(minSum));
    }
};