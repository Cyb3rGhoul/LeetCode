class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int can = nums[0];
        for(int i = 0; i<n; i++){
            if(nums[i]==can) count++;
            else if(count == 0) {can = nums[i]; count++;}
            else if(nums[i]!=can && count!=0) count--;
        }
        return can;
        
    }
};