class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        for(int i = 1; i<n; i++){
            if(j==1 || nums[i]!=nums[j-2]){
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};