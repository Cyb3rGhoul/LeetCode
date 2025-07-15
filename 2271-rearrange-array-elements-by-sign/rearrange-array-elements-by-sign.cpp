class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;
        for(int i = 0; i<n; i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        int idx1 = 0, idx2 = 0;
        for(int i = 0; i<n; i++){
            if(i%2==0) nums[i] = pos[idx2++];
            else nums[i] = neg[idx1++];
        }
        return nums;
    }
};