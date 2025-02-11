class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int res = 0;
        while(l<r){
            if(nums[l]+nums[r]==k){
                res++;
                l++;
                r--;
            }
            else if(nums[l]+nums[r]>k){
                r--;
            }
            else l++;
        }
        return res;
    }
};