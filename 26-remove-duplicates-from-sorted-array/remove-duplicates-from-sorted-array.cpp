class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int i = 1;
        if(n==1) return 1;
        while(i<n){
            if(nums[i]!=nums[i-1]){
                nums[k++]=nums[i];
            }
            i++;
        }
        return k;
    }
};