class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
       
        if(nums[n-1] < 0) return nums[n-1];
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                sum += nums[i];
                while(i + 1 < n && nums[i + 1] == nums[i]) {
                    i++;
                }
            }
        }
        return sum;
    }
};