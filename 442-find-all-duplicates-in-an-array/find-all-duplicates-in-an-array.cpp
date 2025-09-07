class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ctn(n,0);
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(ctn[nums[i]-1]!=0) res.push_back(nums[i]);
            else ctn[nums[i]-1]++;
        }
        return res;
    }
};