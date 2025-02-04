class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int i = 1;
        int sum = nums[0], sum1=nums[0];
        while(i<n){
            if(nums[i]>nums[i-1]){
                sum1+=nums[i];
            }
            else{
                sum1=nums[i];
            }
            sum = max(sum,sum1);
            i++;
        }
        return sum;
    }
};