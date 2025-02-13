class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, ctn = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==1){
                l++;
            }else{
                l = 0;
            }
            ctn = max(ctn,l);
        }
        return ctn;
    }
};