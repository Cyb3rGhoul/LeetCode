class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ctn = 1;
        int l = 0;
        int r = 0;
        while(r<nums.size()){
            if(nums[r]-nums[l]>k){
                ctn++;
                l = r;
            }
             else r++;
        }
        return ctn;
    }
};